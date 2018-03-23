from __future__ import unicode_literals

from django.db import models
from django.utils import timezone
from datetime import datetime

class Room(models.Model):

    # name = models.TextField()
    
    game      = models.TextField()
    label     = models.SlugField(unique=True)
    teacher   = models.TextField()
    isActive  = models.BooleanField() 
    timestamp = models.DateTimeField(default=timezone.now(), db_index=True)


    def __unicode__(self):
        return self.label

class Message(models.Model):

    room      = models.ForeignKey(Room, related_name='messages')
    handle    = models.TextField()
    message   = models.TextField()
    username  = models.TextField()
    timestamp = models.DateTimeField(default=timezone.now(), db_index=True)

    def __unicode__(self):
        return '[{timestamp}] {handle}: {message}'.format(**self.as_dict())

    @property
    def formatted_timestamp(self):
        # return self.timestamp
        return self.timestamp.strftime('%b %d %I:%M %p')
    
    def as_dict(self):
        return {'handle': self.handle, 'message': self.message, 'timestamp': self.formatted_timestamp}