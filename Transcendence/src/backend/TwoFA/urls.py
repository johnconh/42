from django.urls import path
from .views import verify_totp, remove_totp, GetQRView, VerifyTOTPView, RemoveTOTPView, Login2FAView


urlpatterns = [
	path('generate_qr/', GetQRView.as_view(), name='generate_qr'),
	path('verify_totp/', VerifyTOTPView.as_view(), name='verify_totp'),
	path('remove_totp/', RemoveTOTPView.as_view(), name='remove_totp'),
	path('login_2fa/', Login2FAView.as_view(), name='login_2fa'),
]
