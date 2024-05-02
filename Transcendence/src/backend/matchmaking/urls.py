from django.urls import path
from .views import join_queue, leave_queue, matchmake


urlpatterns = [
	path('join_queue/', join_queue.as_view(), name='join_queue'),
	path('leave_queue/', leave_queue.as_view(), name='leave_queue'),
	path('matchmake/', matchmake.as_view(), name='matchmake'),
	]