from asgiref.sync import async_to_sync
from channels.generic.websocket import WebsocketConsumer
from .models import Room
import json
from django.utils import timezone
import datetime

class ChatConsumer(WebsocketConsumer):
    def connect(self):
      print("connect")
      self.room_label = self.scope['url_route']['kwargs']['room_label']
      self.room_group_name = 'chat_%s' % self.room_label
      
      # Join room group
      async_to_sync(self.channel_layer.group_add)(
          self.room_group_name,
          self.channel_name
      )
      # Accepts the WebSocket connection
      self.accept()


      room = Room.objects.get(label=self.room_label)
      messages = room.messages.order_by('timestamp')
      msgList = []
      
      for message in messages:
          # print(message.timestamp.strftime("%H:%M"))
          msgList.append({
            'key': message.key,
            'username': message.username,
            'message':  message.message,
            'timestamp': message.timestamp.strftime("%H:%M")
          })
      async_to_sync(self.channel_layer.group_send)(
          self.room_group_name,
          {
              'type': 'init_message',
              'messages': msgList
          }
      )



    # receive message from websocket and send message to group
    def receive(self, text_data):
        text_data_json = json.loads(text_data)
        msg_type = text_data_json['type']
        key = text_data_json['key']
        username = text_data_json['username']
        message  = text_data_json['message']
        label    = text_data_json['label']
        print(text_data_json)

        if msg_type == 'chat':
            room = Room.objects.get(label=label)
            msg = room.messages.create(key=key, message=message, username=username)
            async_to_sync(self.channel_layer.group_send)(
                self.room_group_name,
                {
                    'type': 'chat_message',
                    'key': key,
                    'username': username,
                    'message': message,
                    'timestamp': msg.timestamp.strftime("%H:%M")
                }
            )
        elif msg_type == 'leave':
            # Room.objects.get(label=label).delete()
            async_to_sync(self.channel_layer.group_send)(
                self.room_group_name,
                {
                    'type': 'leave_message',
                    'username': username
                }
            )

    def disconnect(self, close_code):

        # Leave room group
        async_to_sync(self.channel_layer.group_discard)(
            self.room_group_name,
            self.channel_name
        )

    def init_message(self, event):

        # Send message to WebSocket
        self.send(text_data=json.dumps({
            'type': 'init',
            'messages': event['messages'],
        }))

    # Receive message from room group
    def chat_message(self, event):
        
        # Send message to WebSocket
        self.send(text_data=json.dumps({
            'type': 'chat',
            'key': event['key'],
            'username': event['username'],
            'message':  event['message'],
            'timestamp':  event['timestamp']
        }))

    def leave_message(self, event):

        print(event)
        # Send message to WebSocket
        self.send(text_data=json.dumps({
            'type': 'leave',
            'username': event['username'],
            'message': '離開遊戲'
        }))