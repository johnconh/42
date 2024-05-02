from django.db import models
from accounts.models import User
from django.contrib.auth.models import AbstractBaseUser, PermissionsMixin
from django.utils.translation import gettext_lazy as _
from rest_framework_simplejwt.tokens import RefreshToken


from accounts.managers import UserManager
import os
from datetime import datetime
from datetime import timedelta

# Create your models here.
class Game(models.Model):
    player1 = models.CharField(max_length=100, verbose_name=_('Username'))
    player2 = models.CharField(max_length=100, verbose_name=_('Username'))
    date = models.DateTimeField(auto_now_add=True)
    player1_result = models.PositiveIntegerField(default=0)
    player2_result = models.PositiveIntegerField(default=0)
    mode = models.CharField(max_length=255, choices=[('tournament', 'Tournament'), ('matchmaking', 'Matchmaking')])
    
    def __str__(self):
        return f'{self.player1} vs {self.player2} - {self.date} - {self.mode} result: {self.player1_result} : {self.player2_result}'

    class Meta:
        app_label = 'tournament_pong'