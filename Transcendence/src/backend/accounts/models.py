from django.db import models
from django.contrib.auth.models import AbstractBaseUser, PermissionsMixin
from django.utils.translation import gettext_lazy as _
from rest_framework_simplejwt.tokens import RefreshToken


from accounts.managers import UserManager
import os
from datetime import datetime
from datetime import timedelta
import jwt




class User(AbstractBaseUser, PermissionsMixin):
    id = models.BigAutoField(primary_key=True, editable=False)
    user_name = models.CharField(max_length=100, verbose_name=_('Username'), unique=True)
    email = models.EmailField(max_length=255, verbose_name=_('Email Address'), unique=True)
    first_name = models.CharField(max_length=100, verbose_name=_('First Name'))
    last_name = models.CharField(max_length=100, verbose_name=_('Last Name'))
    birthdate = models.DateField(verbose_name=_('Date of Birth (YYYY-MM-DD)'))
    is_staff = models.BooleanField(default=False)
    is_superuser = models.BooleanField(default=False)
    is_verified = models.BooleanField(default=False)
    is_active = models.BooleanField(default=True)
    date_joined = models.DateTimeField(auto_now_add=True)
    last_login = models.DateTimeField(auto_now=True)
    avatar = models.ImageField(default='user.png')
    cover_image = models.ImageField(default='cover.png')
    games_played = models.PositiveIntegerField(default=0)
    games_won = models.PositiveIntegerField(default=0)
    games_lost = models.PositiveIntegerField(default=0)
    secret = models.CharField(max_length=100, blank=True, null=True)
    is42 = models.BooleanField(default=False)
    lang = models.CharField(default='en', max_length=4, verbose_name=_('Preferred Language'))

    USERNAME_FIELD = 'user_name'
    REQUIRED_FIELDS = ['email', 'first_name', 'last_name', 'birthdate']

    objects = UserManager()


    def __str__(self):
        if self.is_superuser:
            return f'{self.user_name} (admin)'
        return self.user_name

    @property
    def get_full_name(self):
        return f'{self.first_name.title()} {self.last_name.title()}'


    def tokens(self):
        refresh = RefreshToken.for_user(self)
        return {
            "refresh":str(refresh),
            "access":str(refresh.access_token)
        }

class OneTimePassword(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    otp = models.CharField(max_length=6)


    def __str__(self):
        return f"{self.user.user_name} - otp code"
