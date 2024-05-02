from django.http import HttpResponse
from django.shortcuts import render
from conf.settings import MEDIA_ROOT
from accounts.models import User
import pyotp
import qrcode
import io
import jwt
import os
from PIL import Image
from django.core.files.base import ContentFile
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth import authenticate
from rest_framework.generics import GenericAPIView
from rest_framework.permissions import IsAuthenticated
from rest_framework.response import Response
from rest_framework import status


class GetQRView(GenericAPIView):
    permission_classes = [IsAuthenticated]
     
    def get(self, request):
        user_name = request.GET.get('user_name')    
        secret = pyotp.random_base32()
        otpauth_url = pyotp.totp.TOTP(secret).provisioning_uri(name=user_name, issuer_name='Ultimate PONG')
        print(otpauth_url )
        return Response({'outpath_url': otpauth_url, 'qr_secret': secret }, status=status.HTTP_200_OK)

class VerifyTOTPView(GenericAPIView):
    permission_classes = [IsAuthenticated]

    def post(self, request):
        user_name = request.data.get('user_name')
        secret = request.data.get('secret')
        totp=pyotp.TOTP(secret)
        code = request.data.get('code')
        is_valid = totp.verify(code)
        if is_valid:
            user = User.objects.get(user_name=user_name)
            user.secret = secret
            user.save()
            return Response({'message': 'Code is valid!' }, status=status.HTTP_200_OK)
        else:
            return Response({'message': 'Invalid code!' }, status=status.HTTP_400_BAD_REQUEST)

class RemoveTOTPView(GenericAPIView):
    permission_classes = [IsAuthenticated]

    def post(self, request):
        user_name = request.data.get('user_name') 
        user = User.objects.get(user_name=user_name)
        user.secret = None
        user.save()
        return Response({'message': '2FA removed!' }, status=status.HTTP_200_OK)

class Login2FAView(GenericAPIView):
    # permission_classes = [IsAuthenticated]

    def post(self, request):
        user_name = request.data.get('user_name')
        print('user_name:', user_name)
        secret = User.objects.get(user_name=user_name).secret
        print('secret:', secret)
        code = request.data.get('code')
        print('code:', code)
        totp = pyotp.TOTP(secret)
        is_valid = totp.verify(code)
        if is_valid:
            return Response({'message': 'Code is valid!' }, status=status.HTTP_200_OK)
        else:
            return Response({'message': 'Invalid code!' }, status=status.HTTP_400_BAD_REQUEST)

@csrf_exempt
def generate_qr(request):
    user_name = request.GET.get('user_name')    
    secret = pyotp.random_base32()

    # user = User.objects.get(user_name=user_name)
    # user.secret = secret
    # user.save()
    # print('user secret:', user.secret)
    otpauth_url = pyotp.totp.TOTP(secret).provisioning_uri(name=user_name, issuer_name='Ultimate PONG')

    qr = qrcode.make(otpauth_url)

    buf = io.BytesIO()
    qr.save(buf, format='PNG')
    image_qr = buf.getvalue()

    # with open(os.path.join(MEDIA_ROOT, f'{user_name}_qr.png'), 'wb') as f:
    #     f.write(image_stream)
    #return HttpResponse('QR code generated!')
    return (image_qr, secret)

def verify_totp(request):

    user_name = request.GET.get('user_name')   
    secret = request.GET.get('secret')
    #secret = User.objects.get(user_name='john').secret
    totp=pyotp.TOTP(secret)
    generated_totp = totp.now()

    if request.method == 'POST':
        code = request.POST.get('code')
        is_valid = totp.verify(code)
        if is_valid:
            user = User.objects.get(user_name=user_name)
            user.secret = secret
            user.save()
            return HttpResponse('Code is valid!', status=200)
        else:
            return HttpResponse('Invalid code!', status=400)

    #return render(request, 'TwoFA/generate_qr.html', {'generated_totp': generated_totp})
    return request

def remove_totp(request):

    user_name = request.GET.get('user_name') 
    user = User.objects.get(user_name=user_name)
    user.secret = None
    user.save()

    return HttpResponse('2FA removed!', status=200)

def login2FA(request):
    user_name = request.GET.get('user_name')
    # password = request.GET.get('password')
    secret = User.objects.get(user_name=user_name).secret

    # user = authenticate(User, user_name=user_name, password=password)
    # if not user:
    #     return HttpResponse('Invalid username and/or password', status=400)

    if request.method == 'POST':
        code = request.POST.get('code')
        totp = pyotp.TOTP(secret)
        is_valid = totp.verify(code)
        if is_valid:
            return HttpResponse('Code is valid!', status=200)
        else:
            return HttpResponse('Invalid code!', status=400)
