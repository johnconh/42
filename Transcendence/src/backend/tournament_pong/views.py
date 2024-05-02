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
from rest_framework.exceptions import AuthenticationFailed
from drf_yasg.utils import swagger_auto_schema
from drf_yasg import openapi
from django.core.exceptions import ValidationError
from rest_framework_simplejwt.authentication import JWTAuthentication
from django.views.decorators.csrf import csrf_exempt
from django.http import HttpResponse, JsonResponse
from django.db import transaction
import threading
from pong.models import Game
from django.db.models import Q

import os
import jwt


from pong.serializers import (
        SaveGameDataSerializer,
        GetUserGamesSerializer,
)

# Create your views here.
class SaveGameDataView(GenericAPIView):
    # permission_classes = [IsAuthenticated]
    serializer_class = SaveGameDataSerializer
    lock = threading.Lock()
    uuids = {}

    def post(self, request):
        print(self.lock)
        serializer = self.serializer_class(data=request.data, context={'request': request})
        uuid = request.data.get('uuid')
        if uuid not in self.uuids or not self.uuids[uuid]:
            if (serializer.is_valid(raise_exception=True)):
                self.lock.acquire()
                try:
                    self.uuids[uuid] = True
                    serializer.save()
                finally:
                    self.lock.release()
                print("PARTIDA GUARDADA")

        else:
            self.lock.acquire()
            try:
                del self.uuids[uuid]
            finally:
                self.lock.release()
            print("LA  PARTIDA YA SE HA GUARDAD")
        return Response({'message': 'Avatar updated successfully'}, status=status.HTTP_200_OK)

class GetUserGamesView(GenericAPIView):
    serializer_class = GetUserGamesSerializer

    def post(self, request):
        # Obtener el user_name proporcionado en los parámetros de consulta de la solicitud
        user_name = request.data.get('user_name')

        # Verificar si se proporcionó un user_name
        if not user_name:
            return Response({'error': 'Invalid user_name'}, status=status.HTTP_400_BAD_REQUEST)

        # Filtrar las partidas que cumplen con los criterios de búsqueda
        games = Game.objects.filter(Q(player1=user_name) | Q(player2=user_name))
        if not games:
            return Response({'error': 'No games found for the specified user'}, status=status.HTTP_404_NOT_FOUND)

        # Crear una instancia del serializador con el contexto actual
        serializer = self.serializer_class(games, many=True)

        # Devolver la respuesta JSON con los datos serializados de las partidas
        return Response(serializer.data, status=status.HTTP_200_OK)