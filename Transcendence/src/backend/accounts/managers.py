from django.contrib.auth.models import BaseUserManager
from django.core.exceptions import ValidationError
from django.core.validators import validate_email
from django.utils.translation import gettext_lazy as _


class UserManager(BaseUserManager):
    def email_validator(self, email):
        try:
            validate_email(email)
        except ValidationError:
            raise ValueError(_("Please enter a valid email address"))

    def create_user(self, user_name, email, first_name, last_name, birthdate, password, **extra_fields):
        if not user_name:
            raise ValueError(_("Username is required"))
        if email:
            email = self.normalize_email(email)
            self.email_validator(email)
        else:
            raise ValueError(_("Email address is required"))
        if not first_name:
            raise ValueError(_("First name is required"))
        if not last_name:
            raise ValueError(_("Last name is required"))
        if not birthdate:
            raise ValueError(_("Date of Birth is required"))
        user = self.model(user_name=user_name, email=email, first_name=first_name, last_name=last_name, birthdate=birthdate, **extra_fields)
        user.set_password(password)
        user.save(using=self._db)
        return user
    
    def create_user42(self, user_name, email, first_name, last_name, birthdate, **extra_fields):
        if not user_name:
            raise ValueError(_("Username is required"))
        if email:
            email = self.normalize_email(email)
            self.email_validator(email)
        else:
            raise ValueError(_("Email address is required"))
        if not first_name:
            raise ValueError(_("First name is required"))
        if not last_name:
            raise ValueError(_("Last name is required"))
        if not birthdate:
            raise ValueError(_("Date of Birth is required"))
        user = self.model(user_name=user_name, email=email, first_name=first_name, last_name=last_name, birthdate=birthdate, **extra_fields)
        user.save(using=self._db)
        return user

    def create_superuser(self, user_name, email, first_name, last_name, birthdate, password, **extra_fields):
        extra_fields.setdefault("is_staff", True)
        extra_fields.setdefault("is_superuser", True)
        extra_fields.setdefault("is_verified", True)

        if extra_fields.get("is_staff") is not True:
            raise ValueError(_("is_staff must be true for admin user"))

        if extra_fields.get("is_superuser") is not True:
            raise ValueError(_("is_superuser must be true for admin user"))

        if extra_fields.get("is_verified") is not True:
            raise ValueError(_("is_verified must be true for admin user"))

        user = self.create_user(user_name, email, first_name, last_name, birthdate, password, **extra_fields)
        user.save(using=self._db)
        return user