from email.policy import default
from rest_framework import serializers
from django.contrib.auth import authenticate
from rest_framework.exceptions import AuthenticationFailed
from django.contrib.auth.tokens import PasswordResetTokenGenerator
from django.utils.http import urlsafe_base64_decode, urlsafe_base64_encode
from django.utils.encoding import smart_str, force_str, smart_bytes
from django.contrib.sites.shortcuts import get_current_site
from django.urls import reverse
from rest_framework_simplejwt.tokens import RefreshToken, TokenError
from django.core.mail import EmailMessage
from django.conf import settings
from asgiref.sync import sync_to_async

from pong.models import Game
from accounts.models import User
import jwt
import os
from datetime import datetime, timedelta



class SaveGameDataSerializer(serializers.ModelSerializer):
    player1 = serializers.CharField(max_length=68, min_length=3, write_only=True)
    player2 = serializers.CharField(max_length=68, min_length=3, write_only=True)
    player1_result = serializers.IntegerField(write_only=True)
    player2_result = serializers.IntegerField(write_only=True)
    mode = serializers.ChoiceField(choices=[('tournament', 'Tournament'), ('matchmaking', 'Matchmaking')])

    class Meta:
        model = Game
        fields = ['player1', 'player2', 'player1_result', 'player2_result', 'mode']

    def validate(self, attrs):
        return attrs

    def create(self, validated_data):
        game = Game.objects.create(
            player1=validated_data.get('player1'),
            player2=validated_data.get('player2'),
            player1_result=validated_data.get('player1_result'),
            player2_result=validated_data.get('player2_result'),
            mode=validated_data.get('mode'),
        )
        return game
        return validate_data

class GetUserGamesSerializer(serializers.ModelSerializer):
    player1 = serializers.CharField(max_length=68, min_length=3, read_only=True)
    player2 = serializers.CharField(max_length=68, min_length=3, read_only=True)
    player1_result = serializers.IntegerField(read_only=True)
    player2_result = serializers.IntegerField(read_only=True)
    mode = serializers.ChoiceField(choices=[('tournament', 'Tournament'), ('matchmaking', 'Matchmaking')], read_only=True)
    date = serializers.DateTimeField(read_only=True)

    class Meta:
        model = Game
        fields = ['player1', 'player2', 'player1_result', 'player2_result', 'mode', 'date']
