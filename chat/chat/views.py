import random
import string
from django.db import transaction
from django.shortcuts import render, redirect
import haikunator
from .models import Room
from django.http import HttpResponse,JsonResponse
from django.utils import timezone
from datetime import datetime

def about(request):
    return render(request, "chat/about.html")
  
# @require_POST
def new_room(request):
    """
    Randomly create a new room, and redirect to it.
    """

   
    # label  = request.POST.get("label", "")
    

    # if Room.objects.filter(label=label).exists():
    #     return HttpResponse("label already exists.")

    label = ""
    game = request.POST.get("game", "")
    teacher = request.POST.get("teacher", "")
    new_room = None
    while not new_room:
        with transaction.atomic():
            # label = haikunator.haikunate()
            label = ''.join(random.choices(string.ascii_lowercase + string.digits, k=6))
            if Room.objects.filter(label=label).exists():
                continue
            new_room = Room.objects.create(teacher=teacher, label=label, game=game, isActive=True)
    return HttpResponse(label)
    # return redirect(chat_room, label=label)

def update_room(request):

    label    = request.POST.get("label")
    isActive = request.POST.get("isActive")=="true"
    Room.objects.filter(label=label).update(isActive=isActive)
    return HttpResponse("更新成功") 

def chat_room(request, label):
    """
    Room view - show the room, with latest messages.

    The template for this view has the WebSocket business to send and stream
    messages, so see the template for where the magic happens.
    """
    # If the room with the given label doesn't exist, automatically create it
    # upon first visit (a la etherpad).
    room = Room.objects.get(label=label)

    # We want to show the last 50 messages, ordered most-recent-last
    messages = reversed(room.messages.order_by('-timestamp')[:50])

    return render(request, "chat/room.html", {
        'room': room,
        'messages': messages,
    })
