from django.conf.urls import url
from . import views

urlpatterns = [

  # url(r'^$', views.index, name='index'),
  url(r'^new/$', views.new_room, name='new_room'),
  url(r'^getAllRooms/$', views.get_all_rooms),
  # url(r'^updateRoom/$', views.update_room),
  url(r'^authRoom/$', views.auth_room),
  url(r'^getTeams/$', views.get_teams),
  url(r'^closeGame/$', views.close_game),
  # url(r'^(?P<room_label>[^/]+)/$', views.room, name='room'),
]

