from django.contrib.auth.models import BaseUserManager
from django.core.exceptions import ValidationError
from django.core.validators import validate_email
from django.utils.translation import gettext_lazy as _


class UserManager(BaseUserManager):
    def create_user(self, player1, player2, player1_result, player2_result, mode, **extra_fields):
        user = self.model(user_name=user_name, email=email, first_name=first_name, last_name=last_name, birthdate=birthdate, **extra_fields)
        user.set_password(password)
        user.save(using=self._db)
        return user
