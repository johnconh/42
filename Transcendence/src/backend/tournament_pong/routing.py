from django.urls import re_path
from . import consumers

websocket_urlpatterns = [
    re_path(
        r'(?P<game_id>.+)&(?P<playername>.+)/$',
        consumers.GameConsumer.as_asgi()
    ),
]