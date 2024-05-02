from django.shortcuts import render
from rest_framework.generics import GenericAPIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework.permissions import IsAuthenticated
from django.utils.http import urlsafe_base64_decode
from django.utils.encoding import smart_str, DjangoUnicodeDecodeError
from django.contrib.auth.tokens import PasswordResetTokenGenerator
from django.core.mail import EmailMessage
from django.conf import settings
from drf_yasg.utils import swagger_auto_schema
from drf_yasg import openapi
from django.core.exceptions import ValidationError
from rest_framework_simplejwt.authentication import JWTAuthentication
from django.views.decorators.csrf import csrf_exempt
from django.http import HttpResponse, JsonResponse
import os
import jwt




from accounts.serializers import (
    UserRegisterSerializer,
    LoginSerializer,
    UserRegisterSerializer42,
    LoginSerializer42,
    PasswordResetRequestSerializer,
    SetNewPasswordSerializer,
    LogoutUserSerializer,
    SessionSerializer,
    ApiTestSerializer,
    VerifyUserEmailSerializer,
    PasswordResetConfirmSerializer,
    ProfileDataSerializer,
    UsernameSerializer,
    UpdateUserSerializer,
    UpdateAvatarSerializer,
    LanguageSerializer,
)
from accounts.models import User, OneTimePassword
from accounts.otp import generateOtp


def send_code_to_user(email):
    otp = generateOtp()
    user = User.objects.get(email=email)

    OneTimePassword.objects.create(user=user, otp=otp)

    EmailMessage(
        subject = 'Ultimate PONG - Account Verification',
        body = f"Hi {user.first_name},\nThanks for signing up on Ultimate PONG.\nPlease verify your email with the follwoing one time password:\n\n{otp}\n\n\nUltimate PONG team",
        from_email = settings.EMAIL_HOST_USER,
        to = [user.email]
    ).send()


class RegisterView(GenericAPIView):
    serializer_class = UserRegisterSerializer

    def post(self, request):
        serializer = self.serializer_class(data=request.data)
        if serializer.is_valid(raise_exception=True):
            serializer.save()
            user = serializer.data
            send_code_to_user(user['email'])
            return Response({
                'data':user,
                'message': 'Thanks for signing up. An email has be sent to verify your account'
            }, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class RegisterView42(GenericAPIView):
    serializer_class = UserRegisterSerializer42

    def post(self, request):
        serializer = self.serializer_class(data=request.data)
        if serializer.is_valid(raise_exception=True):
            serializer.save()
            user = serializer.data
            return Response({
                'data':user,
                'message': 'Thanks for signing up'
            }, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


class VerifyUserEmailView(GenericAPIView):
    serializer_class = VerifyUserEmailSerializer

    def post(self, request):
        try:
            otp = request.data.get('otp')
            otp_obj = OneTimePassword.objects.get(otp=otp)
            user = otp_obj.user
            if not user.is_verified:
                user.is_verified = True
                user.save()
                otp_obj.delete()
                return Response(
                    {'message':'Email verified successfully'},
                    status=status.HTTP_200_OK
                )
            return Response(
                {'message':'User is already verified'},
                status=status.HTTP_406_NOT_ACCEPTABLE
            )
        except OneTimePassword.DoesNotExist as identifier:
            return Response(
                {'message':'OTP not available'},
                status=status.HTTP_400_BAD_REQUEST
            )


class LoginUserView(GenericAPIView):
    serializer_class = LoginSerializer
    def post(self, request):
        serializer = self.serializer_class(data=request.data, context={'request': request})
        serializer.is_valid(raise_exception=True)
        return Response(serializer.data, status=status.HTTP_200_OK)


class LoginUserView42(GenericAPIView):
    serializer_class = LoginSerializer42
    def post(self, request):
        serializer = self.serializer_class(data=request.data, context={'request': request})
        serializer.is_valid(raise_exception=True)
        return Response(serializer.data, status=status.HTTP_200_OK)


class AuthAPITestView(GenericAPIView):
    permission_classes = [IsAuthenticated]
    serializer_class = ApiTestSerializer

    @swagger_auto_schema(
        manual_parameters=[
            openapi.Parameter(
                'Authorization',
                in_=openapi.IN_HEADER,
                type=openapi.TYPE_STRING,
                description='Bearer <your access token>'
            )
        ],
        responses={200: ApiTestSerializer}
    )
    def get(self, request):
        print(f'Authenticated API call from {request.user}, using token:\n{request.auth}')
        serializer = self.serializer_class()
        # data = {'message':'the authenticated API Call worked!!'}
        return Response(serializer.data, status=status.HTTP_200_OK)

class SessionView(GenericAPIView):
    permission_classes = [IsAuthenticated]
    serializer_class = SessionSerializer

    @swagger_auto_schema(
        manual_parameters=[
            openapi.Parameter(
                'Authorization',
                in_=openapi.IN_HEADER,
                type=openapi.TYPE_STRING,
                description='Bearer <your access token>'
            )
        ],
        responses={200: SessionSerializer}
    )
    @csrf_exempt
    def get(self, request):
        serializer = self.serializer_class({'isAuthenticated': True})
        return Response(serializer.data, status=status.HTTP_200_OK)


class PasswordResetRequestView(GenericAPIView):
    serializer_class = PasswordResetRequestSerializer

    def post(self, request):
        serializer = self.serializer_class(data=request.data, context={'request':request})
        serializer.is_valid(raise_exception=True)
        return Response(
            {'message':'A link has been sent to reset your password'},
            status=status.HTTP_200_OK
        )


class PasswordResetConfirmView(GenericAPIView):
    serializer_class = PasswordResetConfirmSerializer

    def get(self, request, uidb64, token):
        serializer = self.get_serializer(data=request.query_params)
        serializer.is_valid(raise_exception=True)

        try:
            user_id = smart_str(urlsafe_base64_decode(uidb64))
            user = User.objects.get(id=user_id)

            if not PasswordResetTokenGenerator().check_token(user, token):
                raise ValidationError('Token is invalid or has expired')

            return Response(
                {
                    'success':True,
                    'message':'credentials are valid',
                    'uidb64':uidb64,
                    'token':token
                },
                status=status.HTTP_200_OK
            )
        except DjangoUnicodeDecodeError:
            raise ValidationError('Token is invalid or has expired')


class SetNewPasswordView(GenericAPIView):
    serializer_class = SetNewPasswordSerializer

    def patch(self, request):
        serializer = self.serializer_class(data=request.data)
        serializer.is_valid(raise_exception=True)
        return Response(
            {
                'success':True,
                'message':"password reseted"
            },
            status=status.HTTP_200_OK
        )


class LogoutApiView(GenericAPIView):
    serializer_class = LogoutUserSerializer
    permission_classes = [IsAuthenticated]

    def post(self, request):
        serializer=self.serializer_class(data=request.data)
        serializer.is_valid(raise_exception=True)
        serializer.save()
        return Response(status=status.HTTP_204_NO_CONTENT)


class ProfileDataView(GenericAPIView):
    permission_classes = [IsAuthenticated]

    serializer_class = ProfileDataSerializer
    def post(self, request):
        serializer = self.serializer_class(data=request.data, context={'request': request})
        serializer.is_valid(raise_exception=True)
        return JsonResponse(serializer.data, status=200)

class UsernameView(GenericAPIView):
    serializer_class = UsernameSerializer
    @csrf_exempt
    def post(self, request):
        serializer = self.serializer_class(data=request.data, context={'request': request})
        serializer.is_valid(raise_exception=True)
        return JsonResponse(serializer.data, status=200)


class UpdateUserView(GenericAPIView):
    serializer_class = UpdateUserSerializer
    permission_classes = [IsAuthenticated]

    def getId(self, request):
        access_token = request.headers.get('Authorization')[7:].strip()
        secret_key = os.environ['SECRET_KEY']
        payload = jwt.decode(access_token, secret_key, algorithms=["HS256"])
        return(payload.get('user_id'))

    def post(self, request):
        id = self.getId(request)
        user = User.objects.get(id=id)
        serializer = self.serializer_class(user, data=request.data, context={'request': request})
        if serializer.is_valid(raise_exception=True):
            print("ES valido")
            serializer.save()

        return Response({'message': 'User updated successfully'}, status=status.HTTP_200_OK)


class UpdateAvatarView(GenericAPIView):
    serializer_class = UpdateAvatarSerializer
    permission_classes = [IsAuthenticated]

    def getId(self, request):
        access_token = request.headers.get('Authorization')[7:].strip()
        secret_key = os.environ['SECRET_KEY']
        payload = jwt.decode(access_token, secret_key, algorithms=["HS256"])
        return(payload.get('user_id'))

    def post(self, request):
        id = self.getId(request)
        user = User.objects.get(id=id)
        serializer = self.serializer_class(user, data=request.data, context={'request': request})
        if serializer.is_valid(raise_exception=True):
            if (user.avatar and user.avatar.name != 'user.png'):
                user.avatar.delete()
            print("ES valido")
            serializer.save()

        return Response({'message': 'Avatar updated successfully'}, status=status.HTTP_200_OK)

class LanguageView(GenericAPIView):
    permission_classes = [IsAuthenticated]
    serializer_class = LanguageSerializer

    def getId(self, request):
        access_token = request.headers.get('Authorization')[7:].strip()
        secret_key = os.environ['SECRET_KEY']
        payload = jwt.decode(access_token, secret_key, algorithms=["HS256"])
        return(payload.get('user_id'))

    @csrf_exempt
    def post(self, request):
        id = self.getId(request)
        user = User.objects.get(id=id)
        serializer = self.serializer_class(user, data=request.data, context={'request': request})
        if serializer.is_valid(raise_exception=True):
            serializer.save()
        return Response({'message': 'Avatar updated successfully'}, status=status.HTTP_200_OK)
