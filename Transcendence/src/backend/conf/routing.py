from django.urls import path, include, re_path
from channels.routing import ProtocolTypeRouter, URLRouter
from pong.routing import websocket_urlpatterns as pong_websocket_urlpatterns
from matchmaking_skt.routing import websocket_urlpatterns as matchmaking_websocket_urlpatterns
from tournament.routing import websocket_urlpatterns as tournament_websocket_urlpatterns
from tournament_pong.routing import websocket_urlpatterns as tournament_pong_websocket_urlpatterns

websocket_urlpatterns = [
    path('ws/tournament_pong/', URLRouter(tournament_pong_websocket_urlpatterns)),
    path('ws/game/', URLRouter(pong_websocket_urlpatterns)),
    path('ws/matchmaking_skt/', URLRouter(matchmaking_websocket_urlpatterns)),
    path('ws/tournament/', URLRouter(tournament_websocket_urlpatterns)),
]