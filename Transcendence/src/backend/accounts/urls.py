from django.urls import path
from accounts.views import (
    RegisterView,
    VerifyUserEmailView,
    LoginUserView,
    AuthAPITestView,
    PasswordResetRequestView,
    PasswordResetConfirmView,
    SetNewPasswordView,
    LogoutApiView,
    SessionView,
    ProfileDataView,
    UsernameView,
    UpdateUserView,
    UpdateAvatarView,
    LanguageView,
)
from rest_framework_simplejwt.views import TokenRefreshView

urlpatterns = [
    path('register/', RegisterView.as_view(), name='register'),
    path('verify-email/', VerifyUserEmailView.as_view(), name='verify'),
    path('login/', LoginUserView.as_view(), name='login'),
    path('token-refresh/', TokenRefreshView.as_view()),
    path('test/', AuthAPITestView.as_view(), name='test'),
    path('reset-password/', PasswordResetRequestView.as_view(), name='reset-password'),
    path('reset-password-confirm/<uidb64>/<token>', PasswordResetConfirmView.as_view(), name='reset-password-confirm'),
    path('set-new-password/', SetNewPasswordView.as_view(), name='set-new-password'),
    path('logout/', LogoutApiView.as_view(), name='logout'),
    path('session/', SessionView.as_view(), name='session'),
    path('profile-data/', ProfileDataView.as_view(), name='profile-data'),
    path('username/', UsernameView.as_view(), name='username'),
    path('update-user/', UpdateUserView.as_view(), name='update-user'),
    path('update-avatar/', UpdateAvatarView.as_view(), name='update-avatar'),
    path('change-lang/', LanguageView.as_view(), name='change-lang'),
]
