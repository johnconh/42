from django.urls import path
from .views import login42, complete42


urlpatterns = [
	path('login42/', login42, name='login42'),
	path('complete42/', complete42, name='complete42'),
]
