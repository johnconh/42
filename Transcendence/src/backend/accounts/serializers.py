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

from accounts.models import User
import jwt
import os
from datetime import datetime, timedelta



class UserRegisterSerializer(serializers.ModelSerializer):
    password = serializers.CharField(max_length=68, min_length=6, write_only=True)
    password2 = serializers.CharField(max_length=68, min_length=6, write_only=True)

    class Meta:
        model = User
        fields = ['user_name', 'email', 'first_name', 'last_name', 'birthdate', 'password', 'password2']

    def validate(self, attrs):
        password = attrs.get('password', '')
        password2 = attrs.get('password2', '')
        if password != password2:
            raise serializers.ValidationError('passwords do not match')
        return attrs

    def create(self, validated_data):
        user = User.objects.create_user(
            user_name = validated_data.get('user_name'),
            email = validated_data.get('email'),
            first_name = validated_data.get('first_name'),
            last_name = validated_data.get('last_name'),
            birthdate = validated_data.get('birthdate'),
            password = validated_data.get('password')
        )
        return user

class UserRegisterSerializer42(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['user_name', 'email', 'first_name', 'last_name', 'birthdate']

    def validate(self, attrs):
        return attrs

    def create(self, validated_data):
        user = User.objects.create_user42(
            user_name = validated_data.get('user_name'),
            email = validated_data.get('email'),
            first_name = validated_data.get('first_name'),
            last_name = validated_data.get('last_name'),
            birthdate = validated_data.get('birthdate'),
            is_verified = True,
            is42 = True
        )
        return user

class LoginSerializer(serializers.ModelSerializer):
    user_name = serializers.CharField(max_length=255, write_only=True)
    password = serializers.CharField(max_length=68, min_length=6, write_only=True)
    full_name = serializers.CharField(max_length=255, read_only=True)
    email = serializers.EmailField(max_length=255, read_only=True)
    first_name = serializers.CharField(max_length=255, read_only=True)
    last_name = serializers.CharField(max_length=255, read_only=True)
    birthdate = serializers.DateField(read_only=True)
    date_joined = serializers.DateTimeField(read_only=True)
    last_login = serializers.DateTimeField(read_only=True)
    avatar = serializers.ImageField(read_only=True)
    cover_image = serializers.ImageField(read_only=True)
    access_token = serializers.CharField(max_length=255, read_only=True)
    refresh_token = serializers.CharField(max_length=255, read_only=True)
    secret = serializers.CharField(max_length=100, read_only=True)
    is42 = serializers.BooleanField(default=False)
    lang = serializers.CharField(max_length=4, read_only=True)

    class Meta:
        model = User
        fields = ['user_name', 'password', 'full_name', 'email', 'first_name', 'last_name', 'birthdate', 'date_joined', 'last_login', 'avatar', 'cover_image', 'access_token', 'refresh_token', 'secret', 'is42', 'lang']

    def validate(self, attrs):
        request = self.context.get('request')
        user_name = attrs.get('user_name')
        password = attrs.get('password')

        user = authenticate(request, user_name=user_name, password=password)
        if not user:
            raise AuthenticationFailed('Invalid username and/or password')
        if not user.is_verified:
            raise AuthenticationFailed('Account is not verified yet')
        tokens = user.tokens()
        return {
            'user_name': user.user_name,
            'email' : user.email,
            'first_name' : user.first_name,
            'last_name' : user.last_name,
            'birthdate' : user.birthdate,
            'date_joined' : user.date_joined,
            'last_login' : user.last_login,
            'avatar' : user.avatar,
            'avatar_fileName': str(user.avatar),
            'cover_image' : user.cover_image,
            'full_name': user.get_full_name,
            'access_token': str(tokens.get('access')),
            'refresh_token': str(tokens.get('refresh')),
            'secret': user.secret,
            'is42': user.is42,
            'lang': user.lang
        }

class LoginSerializer42(serializers.ModelSerializer):
    user_name = serializers.CharField(max_length=255, write_only=True)
    password = serializers.CharField(max_length=68, min_length=6, write_only=True)
    full_name = serializers.CharField(max_length=255, read_only=True)
    email = serializers.EmailField(max_length=255, read_only=True)
    first_name = serializers.CharField(max_length=255, read_only=True)
    last_name = serializers.CharField(max_length=255, read_only=True)
    birthdate = serializers.DateField(read_only=True)
    date_joined = serializers.DateTimeField(read_only=True)
    last_login = serializers.DateTimeField(read_only=True)
    avatar = serializers.ImageField(read_only=True)
    cover_image = serializers.ImageField(read_only=True)
    access_token = serializers.CharField(max_length=255, read_only=True)
    refresh_token = serializers.CharField(max_length=255, read_only=True)
    password = serializers.CharField(required=False)
    is42 = serializers.BooleanField(default=True)
    lang = serializers.CharField(max_length=4, read_only=True)

    class Meta:
        model = User
        fields = ['user_name', 'full_name', 'email', 'first_name', 'last_name', 'birthdate', 'date_joined', 'last_login', 'avatar', 'cover_image', 'access_token', 'refresh_token', 'password', 'is42', 'lang']

    def validate(self, attrs):
        user_name = attrs.get('user_name')
        user = User.objects.get(user_name=user_name)
        if not user:
            raise AuthenticationFailed('Invalid username')
        tokens = user.tokens()
        return {
            'user_name': user.user_name,
            'email' : user.email,
            'first_name' : user.first_name,
            'last_name' : user.last_name,
            'birthdate' : user.birthdate,
            'date_joined' : user.date_joined,
            'last_login' : user.last_login,
            'avatar' : user.avatar,
            'avatar_fileName': str(user.avatar),
            'cover_image' : user.cover_image,
            'full_name': user.get_full_name,
            'access_token': str(tokens.get('access')),
            'refresh_token': str(tokens.get('refresh')),
            'is42': user.is42,
            'lang': user.lang
        }


class VerifyUserEmailSerializer(serializers.Serializer):
    otp = serializers.CharField(max_length=6)


class SessionSerializer(serializers.Serializer):
    isAuthenticated = serializers.BooleanField(default=False)


class ApiTestSerializer(serializers.Serializer):
    sucessMsg = serializers.CharField(max_length=255, default='the authenticated API Call worked!!')


class PasswordResetConfirmSerializer(serializers.Serializer):
    pass


class PasswordResetRequestSerializer(serializers.Serializer):
    email = serializers.EmailField(max_length=255)

    class Meta:
        fields = ['email']

    def validate(self, attrs):
        email = attrs.get('email')
        if User.objects.filter(email=email).exists():
            user = User.objects.get(email=email)
            uidb64 = urlsafe_base64_encode(smart_bytes(user.id))
            token = PasswordResetTokenGenerator().make_token(user)
            request = self.context.get('request')
            relative_link = reverse('reset-password-confirm', kwargs={'uidb64':uidb64, 'token':token})
            link = f'https://{get_current_site(request).domain}{relative_link}'
            EmailMessage(
                subject = 'Ultimate PONG - Password Reset Link',
                body = f'Hi {user.first_name} use the link below to reset your password:\n{link}',
                from_email = settings.EMAIL_HOST_USER,
                to = [user.email]
            ).send()

        return super().validate(attrs)


class SetNewPasswordSerializer(serializers.Serializer):
    password = serializers.CharField(max_length=100, min_length=6, write_only=True)
    password2 = serializers.CharField(max_length=100, min_length=6, write_only=True)
    uidb64 = serializers.CharField(min_length=1, write_only=True)
    token = serializers.CharField(min_length=3, write_only=True)

    class Meta:
        fields = ['password', 'password2', 'uidb64', 'token']

    def validate(self, attrs):
        try:
            token = attrs.get('token')
            uidb64 = attrs.get('uidb64')
            password = attrs.get('password')
            password2 = attrs.get('password2')

            user_id = force_str(urlsafe_base64_decode(uidb64))
            user = User.objects.get(id=user_id)
            if not PasswordResetTokenGenerator().check_token(user, token):
                raise AuthenticationFailed('Reset link is invalid or has expired', 401)
            if password != password2:
                raise AuthenticationFailed('Passwords do not match')
            user.set_password(password)
            user.save()
            return user
        except Exception as e:
            return AuthenticationFailed('Reset link is invalid or has expired')


class LogoutUserSerializer(serializers.Serializer):
    refresh_token = serializers.CharField()

    default_error_message = {
        'bad_token': ('Token is expired or invalid')
    }

    def validate(self, attrs):
        self.token = attrs.get('refresh_token')
        return attrs

    def save(self, **kwargs):
        try:
            token = RefreshToken(self.token)
            token.blacklist()
        except TokenError:
            return self.fail('bad_token')

class ProfileDataSerializer(serializers.Serializer):
    user_name = serializers.CharField(max_length=255, read_only=True)
    full_name = serializers.CharField(max_length=255, read_only=True)
    email = serializers.EmailField(max_length=255, read_only=True)
    first_name = serializers.CharField(max_length=255, read_only=True)
    last_name = serializers.CharField(max_length=255, read_only=True)
    birthdate = serializers.DateField(read_only=True)
    date_joined = serializers.DateTimeField(read_only=True)
    last_login = serializers.DateTimeField(read_only=True)
    avatar = serializers.ImageField(read_only=True)
    avatar_fileName = serializers.CharField(read_only=True)
    cover_image = serializers.ImageField(read_only=True)
    secret = serializers.CharField(max_length=100, read_only=True)
    is42 = serializers.BooleanField(default=False)
    lang = serializers.CharField(max_length=4, read_only=True)

    class Meta:
        model = User
        fields = ['user_name', 'full_name', 'email', 'first_name', 'last_name', 'birthdate', 'date_joined', 'last_login', 'avatar', 'avatar_fileName', 'cover_image', 'is42', 'lang']

    def validate(self, attrs):
        request = self.context.get('request')
        access_token = request.headers.get('Authorization')[7:].strip()
        secret_key = os.environ['SECRET_KEY']
        payload = jwt.decode(access_token, secret_key, algorithms=["HS256"])
        id = payload.get('user_id')


        user = User.objects.filter(id=id)
        if not user.exists():
            raise AuthenticationFailed('Invalid Username')
        user = user.first()
        tokens = user.tokens()
        print("tokens", user.avatar)
        return {
            'user_name': user.user_name,
            'email' : user.email,
            'first_name' : user.first_name,
            'last_name' : user.last_name,
            'birthdate' : user.birthdate,
            'date_joined' : user.date_joined,
            'last_login' : user.last_login,
            'avatar' : user.avatar,
            'avatar_fileName': str(user.avatar),
            'cover_image' : user.cover_image,
            'full_name': user.get_full_name,
            'secret': user.secret,
            'is42': user.is42,
            'lang': user.lang
        }


class UsernameSerializer(serializers.Serializer):
    user_name = serializers.CharField(max_length=255, read_only=True)
    full_name = serializers.CharField(max_length=255, read_only=True)
    avatar = serializers.ImageField(read_only=True)
    avatar_fileName = serializers.CharField(read_only=True)
    games_played = serializers.IntegerField(read_only=True)
    games_won = serializers.IntegerField(read_only=True)
    games_lost = serializers.IntegerField(read_only=True)
    email = serializers.EmailField(max_length=255, read_only=True)
    lang = serializers.CharField(max_length=4, read_only=True)

    class Meta:
        model = User
        fields = ['user_name', 'full_name', 'avatar', 'avatar_fileName' ,'games_played', 'games_won', 'games_lost', 'email', 'lang']

    def validate(self, attrs):
        request = self.context.get('request')
        user_name = request.data.get('user_name')
        if (not user_name):
            raise AuthenticationFailed('You must to provide the user_name')

        user = User.objects.filter(user_name=user_name)
        if not user.exists():
            raise AuthenticationFailed('Invalid Username')
        user = user.first()
        avatarFilename = str(user.avatar)
        return {
            'user_name': user.user_name,
            'avatar' : user.avatar,
            'osi': 'mevengo',
            'avatar_fileName': avatarFilename,
            'full_name': user.get_full_name,
            'games_played': user.games_played,
            'games_won': user.games_won,
            'games_lost': user.games_lost,
            'email': user.email,
            'lang': user.lang
        }


class UpdateUserSerializer(serializers.Serializer):
    new_first_name = serializers.CharField(max_length=255, read_only=True)
    last_name = serializers.CharField(max_length=255, read_only=True)

    class Meta:
        model = User
        fields = ['new_first_name']
        # fields = ['user_name', 'first_name', 'last_name', 'avatar']


    def validate(self, attrs):
        print(attrs)
        return attrs

    def update(self, instance, validated_data):
        request = self.context.get('request')

        new_first_name = request.data.get('new_first_name')
        if (new_first_name):
            instance.first_name = new_first_name

        new_last_name = request.data.get('new_last_name')
        if (new_last_name):
            instance.last_name = new_last_name

        # self.save_value(instance.first_name,request.data.get('new_first_name'))

        instance.save()
        return(instance)


class UpdateAvatarSerializer(serializers.Serializer):
    new_avatar = serializers.ImageField(write_only=True)

    class Meta:
        model = User
        fields = ['avatar']

    def update(self, instance, validated_data):
        request = self.context.get('request')
        new_avatar = request.data.get('new_avatar')
        print(new_avatar)
        fileExtension = new_avatar.name[new_avatar.name.rfind('.'):]
        new_avatar.name = instance.user_name + '_avatar' + fileExtension
        print(new_avatar)
        instance.avatar = new_avatar
        instance.save()
        return(instance)


class LanguageSerializer(serializers.Serializer):
    lang = serializers.CharField(max_length=4, write_only=True)

    class Meta:
        model = User
        fields = ['lang']

    def update(self, instance, validated_data):
        lang = validated_data.get('lang')
        instance.lang = lang
        instance.save()
        return(instance)
