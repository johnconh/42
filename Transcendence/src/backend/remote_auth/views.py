from django.shortcuts import render, redirect
from conf.settings import CLIENT_ID, CLIENT_SECRET, REDIRECT_URI
import requests, secrets
from datetime import datetime
from accounts.models import  User
from accounts.views import LoginUserView42, RegisterView42
from django.http import HttpResponse, JsonResponse
from django.test import RequestFactory
from django.views.decorators.csrf import csrf_exempt
import json
from rest_framework.response import Response
from rest_framework import status

AUTHORIZATION_URL = 'https://api.intra.42.fr/oauth/authorize'
ACCESS_TOKEN_URL = 'https://api.intra.42.fr/oauth/token'
USER_INFO_URL = 'https://api.intra.42.fr/v2/me'

def login42(request):
        STATE_VALLUE = secrets.token_urlsafe(32)
        # https://api.intra.42.fr/oauth/authorize?client_id=your_very_long_client_id&redirect_uri=http%3A%2F%2Flocalhost%3A1919%2Fusers%2Fauth%2Fft%2Fcallback&response_type=code&scope=public&state=a_very_long_random_string_witchmust_be_unguessable'
        authorization = f'{AUTHORIZATION_URL}?client_id={CLIENT_ID}&redirect_uri=https%3A%2F%2Flocalhost%2FftVerify&response_type=code&scope=public&state={STATE_VALLUE}'
        # return redirect(authorization)
        data = {'url': authorization}
        return JsonResponse(data, status=200)

@csrf_exempt
def complete42(request):
	body = request.body.decode('utf-8')
	bodyData = json.loads(body)

	code = bodyData.get('code')
	STATE_VALUE = bodyData.get('state')

	if code:
		data = {
			'grant_type': 'authorization_code',
			'client_id': CLIENT_ID,
			'client_secret': CLIENT_SECRET,
			'code': code,
			'redirect_uri': REDIRECT_URI,
			'state': STATE_VALUE,
		}
		print(data)
		response = requests.post(ACCESS_TOKEN_URL, data=data)
		print(response.json())
		token = response.json().get('access_token')
	
		if token:
			headers = {'Authorization':f'Bearer {token}'}
			response  = requests.get(USER_INFO_URL, headers=headers)
			user_info = response.json()
			user_id_42 = user_info.get('login')
			try:
				User.objects.get(user_name=user_id_42)
			except User.DoesNotExist:
				save_user_info(user_info)
			user = User.objects.get(user_name=user_id_42)
			if user.is42 == False:
				return JsonResponse(
					{'message':'User is already register without 42 account'},
					status=status.HTTP_406_NOT_ACCEPTABLE
				)
			print("USER LOGIN ==", login_user(user_info))
			return JsonResponse (login_user(user_info), status=200)
		return JsonResponse(
			{'message':'Token not found'},
			status=status.HTTP_403_FORBIDDEN
		)
	return JsonResponse(
		{'message':'Code not found'},
		status=status.HTTP_403_FORBIDDEN
	)
	
def save_user_info(user_info):
	user_id_42 = user_info.get('login')
	email = user_info.get('email')
	first_name = user_info.get('first_name')
	last_name = user_info.get('last_name')
	cursus_users = user_info.get('cursus_users')
	image_url = user_info.get('image', {}).get('link')
	if cursus_users:
		for cursus_user in cursus_users:
			begin_at_str = cursus_user.get('begin_at')
			if begin_at_str:
				begin_at_datetime = datetime.strptime(begin_at_str, '%Y-%m-%dT%H:%M:%S.%fZ')
				begin_at = begin_at_datetime.date()
		
	data ={
		'user_name': user_id_42,
        'email': email,
        'first_name': first_name,
        'last_name': last_name,
        'birthdate': begin_at,
		'avatar': image_url,
	}
	factory = RequestFactory()
	request = factory.post('/api/v1/register/', data)
	request.data = data
	register_view = RegisterView42()
	register_view.post(request)

def login_user(user_info):
	user_id_42 = user_info.get('login')
	data={
		'user_name': user_id_42
	}
	factory = RequestFactory()
	request = factory.post('/api/v1/login/', data)
	request.data = data
	reponse = LoginUserView42().post(request)
	return reponse.data

