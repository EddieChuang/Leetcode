from asgiref.sync import async_to_sync
from channels.generic.websocket import WebsocketConsumer
from .models import Room
import json
from django.utils import timezone
import datetime

class ChatConsumer(WebsocketConsumer):

    # def __init__(self):
    #   self.username = ''

    def connect(self):
      print("connect")
      self.room_label = self.scope['url_route']['kwargs']['room_label']
      self.username = self.scope['url_route']['kwargs']['username']
      self.room_group_name = 'chat_%s' % self.room_label
      
      # Join room group
      async_to_sync(self.channel_layer.group_add)(
          self.room_group_name,
          self.channel_name
      )
      # Accepts the WebSocket connection
      self.accept()

      room = Room.objects.get(label=self.room_label)
      
      #如果登入的是老師，老師名字不會和隊伍名稱重複，filter不會過
      if room.teams.filter(name=self.username).exists():
          room.teams.filter(name=self.username).update(inRoom=True)
          room.messages.create(usertype='system', text=self.username+'加入遊戲')
      messages = room.messages.order_by('timestamp')
      msgList = []
      for message in messages:
          # print(message.timestamp.strftime("%H:%M"))
          msgList.append({
            'key': message.key,
            'usertype': message.usertype,
            'username': message.username,
            'text':  message.text,
            'timestamp': message.timestamp.strftime("%H:%M")
          })

      async_to_sync(self.channel_layer.group_send)(
          self.room_group_name,
          {
              'type': 'init_message',
              'messages': msgList
          }
      )

      
      # async_to_sync(self.channel_layer.group_send)(
      #     self.room_group_name,
      #     {
      #         'type': 'chat_message',
      #         'key': msg.key,
      #         'usertype': msg.usertype,
      #         'username': msg.username,
      #         'text': msg.text,
      #         'timestamp': msg.timestamp.strftime("%H:%M")
      #     }
      # )



    # receive message from websocket and send message to group
    def receive(self, text_data):
        data = json.loads(text_data)
        msg_type = data['type']
        key      = data['key']
        usertype = data['usertype']
        username = data['username']
        text  = data['text']
        label    = data['label']

        if msg_type == 'chat':
            room = Room.objects.get(label=label)
            msg = room.messages.create(key=key, usertype=usertype, username=username, text=text)
            async_to_sync(self.channel_layer.group_send)(
                self.room_group_name,
                {
                    'type': 'chat_message',
                    'key': key,
                    'usertype': usertype,
                    'username': username,
                    'text': text,
                    'timestamp': msg.timestamp.strftime("%H:%M")
                }
            )


    def disconnect(self, close_code):

        msg = None
        room = Room.objects.get(label=self.room_label)
        #如果登入的是老師，老師名字不會和隊伍名稱重複，filter不會過
        if room.teams.filter(name=self.username).exists():
            room.teams.filter(name=self.username).update(inRoom=False)
            room.messages.create(usertype='system', text=self.username+'離開遊戲')
        
        async_to_sync(self.channel_layer.group_send)(
            self.room_group_name,
            {
                'type': 'leave_message',
                'key': '',
                'usertype': 'system',
                'username': '',
                'text': self.username + '離開遊戲',
                'timestamp': msg.timestamp.strftime("%H:%M")
            }
        )

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
            'message': {
              'key': event['key'],
              'usertype': event['usertype'],
              'username': event['username'],
              'text': event['text'],
              'timestamp': event['timestamp']
            }
        }))

    def leave_message(self, event):

        print(event)
        # Send message to WebSocket
        self.send(text_data=json.dumps({
            'type': 'leave',
            'message': {
              'key': event['key'],
              'usertype': event['usertype'],
              'username': event['username'],
              'text': event['text'],
              'timestamp': event['timestamp']
            }
        }))