from django.urls import path
from pong.views import (
        SaveGameDataView,
        GetUserGamesView,
)
from rest_framework_simplejwt.views import TokenRefreshView

urlpatterns = [
    path('save-match-data/', SaveGameDataView.as_view(), name='save-match-data/'),
    path('get-user-games/', GetUserGamesView.as_view(), name='get-user-games/'),
]
