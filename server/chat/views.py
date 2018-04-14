from django.shortcuts import render
from django.views.decorators.http import require_POST,require_GET
from django.utils.safestring import mark_safe
from django.http import HttpResponse,JsonResponse
from django.db import transaction
from .models import Room, Team
import random
import string
import json

# Create your views here.

def index(request):
    return render(request, 'chat/index.html', {})

@require_POST
def auth_room(request):

    print('auth_room')
    key  = request.POST.get('key')
    name = request.POST.get('team_name')
    note =  request.POST.get('note')
    team = Team.objects.filter(key=key)
    
    if team :
        team  = team[0]
        room  = team.room
        teams = room.teams.all()  # all teams in the room
        isActive = room.isActive

        if not isActive:
            return JsonRespnose({'res':'遊戲未開啟'}, status=403)
        for team in teams:
            if name == team.name and not(key == team.key):
                return JsonResponse({'res':'隊伍名稱已存在'}, status=403)

        Team.objects.filter(key=key).update(name=name)
        Team.objects.filter(key=key).update(note=note)               
        res_team = {'key':key, 'name':name, 'note':note}
        return JsonResponse({'res':'歡迎進入遊戲', 'label':room.label, 'team':res_team}, status=200)
  
    return JsonResponse({'res':'遊戲金鑰錯誤'}, status=403)

#     @require_POST
# def auth_room(request):

#     label = request.POST.get('label')
#     team_name  = request.POST.get('team_name')
#     note =  request.POST.get('note')
#     room = Room.objects.get(label=label)
#     if room :

#         teams = room.teams.all()
#         nTeam = room.nTeam
#         isActive = room.isActive

#         if not isActive:
#             return JsonRespnose({'res':'遊戲未開啟'}, status=403)
#         if len(teams) >= nTeam:
#             return JsonResponse({'res':'遊戲已滿'}, status=403)
#         for team in teams:
#             if team_name == team.name:
#                 return JsonResponse({'res':'隊伍名稱已存在'}, status=403)
                
#         while True:
#             team_id = label + '-'.join(random.choices(string.digits, k=2))
#             if not Team.objects.filter(team_id=team_id).exists():
#                 Team.objects.create(room=room, team_id=team_id, name=team_name, note=note)
#                 break
#         team = {'id':team_id, 'name':team_name, 'note':note}
#         return JsonResponse({'res':'歡迎進入遊戲', 'label':label, 'team':team}, status=200)
  
#     return JsonResponse({'res':'遊戲不存在'}, status=403)

# no use
def room(request, room_label):

    room = Room.objects.get(label=room_label)
    messages = reversed(room.messages.order_by('-timestamp')[:50])
    # return render(request, "chat/room.html", {
    #     'room': room,
    #     'messages': messages,
    # })

    return JsonResponse({'label':room_label})

    # return render(request, 'chat/room.html', {
    #     'room_label_json': mark_safe(json.dumps(room_label))
    # })

# create a new room by teacher
def new_room(request):

    label = ""
    game = request.POST.get("game", "")
    teacher = request.POST.get("teacher", "")
    nTeam = int(request.POST.get("nTeam", ""))
    new_room = None

    # create a new room without duplicate label
    while not new_room:
        with transaction.atomic():
            label = ''.join(random.choices(string.ascii_lowercase + string.digits, k=8))
            if Room.objects.filter(label=label).exists():
                continue
            new_room = Room.objects.create(teacher=teacher, label=label, game=game, nTeam=nTeam)
    
    # create nTeam keys for the room
    n = 0
    keys = []
    while n < nTeam:
        with transaction.atomic():
          key = label + '-' + ''.join(random.choices(string.ascii_lowercase + string.digits, k=4))
          if not Team.objects.filter(key=key).exists():
              Team.objects.create(room=new_room, key=key)
              keys.append(key)
              n += 1
    return JsonResponse({'teacher':teacher, 'game':game, 'nTeam':nTeam, 'keys': keys, 'label':label})

@require_POST
def update_room(request):

    label    = request.POST.get("label")
    isActive = request.POST.get("isActive")=="true"
    Room.objects.filter(label=label).update(isActive=isActive)
    return HttpResponse("更新成功") 

@require_POST
def get_all_rooms(request):

    username = request.POST.get('username')
    rooms = Room.objects.filter(teacher=username).order_by('-timestamp')
    res = []
    for room in rooms:
        teams = room.teams.all()
        keys = []
        for team in teams:
            keys.append(team.key)
        res.append({
          'isActive': room.isActive==1,
          'teacher': room.teacher,
          'label': room.label,
          'keys': keys,
          'nTeam': room.nTeam,
          'game': room.game
        })
    return JsonResponse({"rooms":res}, status=200)

# 取得指定房間的隊伍
@require_POST
def get_teams(request):

    label = request.POST.get('label')
    room  = Room.objects.get(label=label)
    teams = room.teams.all().order_by('timestamp')
    res = []
    for team in teams:
        res.append({
          'name': team.name
        })
    return JsonResponse({"teams":res}, status=200)