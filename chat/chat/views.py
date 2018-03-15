import random
import string
from django.db import transaction
from django.shortcuts import render, redirect
import haikunator
from .models import Room
from django.http import HttpResponse,JsonResponse # chiamin added

def about(request):
    return render(request, "chat/about.html")



# @require_POST
def new_room(request):
    """
    Randomly create a new room, and redirect to it.
    """

    teacher = request.POST.get("teacher", "")
    label  = request.POST.get("label", "")
    game = request.POST.get("game", "")

    if Room.objects.filter(label=label).exists():
        return HttpResponse("label already exists.")

    new_room = Room.objects.create(teacher=teacher, label=label, game=game)

    return HttpResponse("建立成功")
    # new_room = None
    # while not new_room:
    #     with transaction.atomic():
    #         label = haikunator.haikunate()
    #         if Room.objects.filter(label=label).exists():
    #             continue
    #         new_room = Room.objects.create(game=game, label=label)
    # return redirect(chat_room, label=label)

def chat_room(request, label):
    """
    Room view - show the room, with latest messages.

    The template for this view has the WebSocket business to send and stream
    messages, so see the template for where the magic happens.
    """
    # If the room with the given label doesn't exist, automatically create it
    # upon first visit (a la etherpad).
    room, created = Room.objects.get_or_create(label=label)

    # We want to show the last 50 messages, ordered most-recent-last
    messages = reversed(room.messages.order_by('-timestamp')[:50])

    return render(request, "chat/room.html", {
        'room': room,
        'messages': messages,
    })
