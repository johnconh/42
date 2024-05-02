from pathlib import Path
from datetime import timedelta
import os


# Key parameters

BASE_DIR = Path(__file__).resolve().parent.parent
SECRET_KEY = os.environ['SECRET_KEY']
DEBUG = os.environ['DEBUG']
ROOT_URLCONF = 'conf.urls'
DEFAULT_AUTO_FIELD = 'django.db.models.BigAutoField'



# Application definition

DJANGO_APPS = [
    'daphne',
    "django.contrib.admin",
    "django.contrib.auth",
    "django.contrib.contenttypes",
    "django.contrib.sessions",
    "django.contrib.messages",
    "django.contrib.staticfiles",
    'django_extensions',
    'corsheaders',
]

THIRD_PARTY_APPS = [
    'rest_framework',
    'rest_framework_simplejwt.token_blacklist',
    'drf_yasg',
    'channels',
]

LOCAL_APPS = [
    'accounts',
    'pong',
	'remote_auth',
	'matchmaking',
	'TwoFA',
    'media',
	'tournament',
]

INSTALLED_APPS = DJANGO_APPS + THIRD_PARTY_APPS + LOCAL_APPS


MIDDLEWARE = [
    'django.middleware.security.SecurityMiddleware',
    # 'conf.middleware.MediaMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.common.CommonMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
    'corsheaders.middleware.CorsMiddleware',
]

ASGI_APPLICATION = 'conf.asgi.application'

CHANNEL_LAYERS = {
    'default': {
        'BACKEND': 'channels.layers.InMemoryChannelLayer',
    },
}

# Templates:

TEMPLATES = [
    {
        'BACKEND': 'django.template.backends.django.DjangoTemplates',
        'DIRS': [],
        'APP_DIRS': True,
        'OPTIONS': {
            'context_processors': [
                'django.template.context_processors.debug',
                'django.template.context_processors.request',
                'django.contrib.auth.context_processors.auth',
                'django.contrib.messages.context_processors.messages',
            ],
        },
    },
]


# Database

DATABASES = {
    "default": {
        "ENGINE": "django.db.backends.postgresql",
        "NAME": os.environ['POSTGRES_DB'],
        "USER": os.environ['POSTGRES_USER'],
        "PASSWORD": os.environ['POSTGRES_PASSWORD'],
        "HOST": os.environ['POSTGRES_HOST'],
        "PORT": os.environ['POSTGRES_PORT'],
    }
}


# Authentication

AUTH_USER_MODEL='accounts.User'


REST_FRAMEWORK={
    'NON_FIELD_ERRORS_KEY':'error',
        'DEFAULT_AUTHENTICATION_CLASSES': (
            'rest_framework.authentication.SessionAuthentication',
            'rest_framework_simplejwt.authentication.JWTAuthentication',
        )
}

SIMPLE_JWT = {
    "ACCESS_TOKEN_LIFETIME": timedelta(hours=2),
    "REFRESH_TOKEN_LIFETIME": timedelta(days=1),
    "ROTATE_REFRESH_TOKENS": True,
    "BLACKLIST_AFTER_ROTATION": True,
    "UPDATE_LAST_LOGIN": False,

    "ALGORITHM": "HS256",
    "SIGNING_KEY": SECRET_KEY,
    "VERIFYING_KEY": "",
    "AUDIENCE": None,
    "ISSUER": None,
    "JSON_ENCODER": None,
    "JWK_URL": None,
    "LEEWAY": 0,

    "AUTH_HEADER_TYPES": ("Bearer",),
}

# Password validation

AUTH_PASSWORD_VALIDATORS = [
    {
        'NAME': 'django.contrib.auth.password_validation.UserAttributeSimilarityValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.MinimumLengthValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.CommonPasswordValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.NumericPasswordValidator',
    },
]


# Internationalization

LANGUAGE_CODE = 'en-us'
TIME_ZONE = 'UTC'
USE_I18N = True
USE_TZ = True


# Static files (CSS, JavaScript, Images)

STATIC_URL = 'static/'
STATIC_ROOT = BASE_DIR / 'staticfiles'

MEDIA_URL = '/media/'
MEDIA_ROOT = os.path.join(BASE_DIR, 'media')


# Configurar la api 42 https://api.intra.42.fr/apidoc/guides/getting_started

CLIENT_ID = os.environ['CLIENT42']
CLIENT_SECRET = os.environ['SECRET42']
REDIRECT_URI = os.environ['URI42']


# Allowed Connections from / CORS Config:

ALLOWED_HOSTS = ['testserver', '127.0.0.1', '0.0.0.0', 'localhost', 'host.docker.internal', 'backend']
SECURE_CROSS_ORIGIN_OPENER_POLICY = None
CORS_ALLOW_ALL_ORIGINS = True
CORS_ALLOW_CREDENTIALS = True
CORS_ALLOW_PRIVATE_NETWORK = True


CORS_ALLOW_METHODS = (
    "DELETE",
    "GET",
    "OPTIONS",
    "PATCH",
    "POST",
    "PUT",
)

CORS_ALLOW_HEADERS = (
    "accept",
    "authorization",
    "content-type",
    "user-agent",
    "x-csrftoken",
    "x-requested-with",
)

CORS_ALLOWED_ORIGINS = [
    'http://0.0.0.0:5173',
    'http://localhost:5173',
    'http://127.0.0.1:5173',
    'http://0.0.0.0:61001',
    'http://localhost:61001',
    'http://127.0.0.1:61001',
    'http://0.0.0.0:4000',
    'http://backend:61001',
]

CORS_ALLOWED_HOSTS = [
    'http://0.0.0.0:5173',
    'http://localhost:5173',
    'http://127.0.0.1:5173',
    'http://0.0.0.0:61001',
    'http://localhost:61001',
    'http://127.0.0.1:61001',
    'http://localhost',
    'http://0.0.0.0',
    'http://localhost:4000',
    'http://0.0.0.0:4000',
    'http://backend:61001',
]

CSRF_TRUSTED_ORIGINS = [
    'http://0.0.0.0:5173',
    'http://localhost:5173',
    'http://127.0.0.1:5173',
    'http://0.0.0.0:61001',
    'http://localhost:61001',
    'http://127.0.0.1:61001',
    'http://0.0.0.0:4000',
    'http://backend:61001',
]

# CORS_ORIGIN_WHTIELIST = [
#     'http://0.0.0.0:5173',
#     'http://localhost:5173',
#     'http://127.0.0.1:5173',
#     'http://0.0.0.0:61001',
#     'http://localhost:61001',
#     'http://127.0.0.1:61001',
#     'http://0.0.0.0:4000',
#     'http://backend:61001',
# ]

CORS_ORIGIN_ALLOW_ALL = True

SESSION_COOKIE_SAMESITE = 'None'
CSRF_COOKIE_SAMESITE = 'None'
SESSION_COOKIE_SECURE = True
CSRF_COOKIE_SECURE = True

# EMAIL_HOST = 'sandbox.smtp.mailtrap.io'
# EMAIL_HOST_USER = '5767f95fd0e11d'
# EMAIL_HOST_PASSWORD = 'a875b868c066dd'
# EMAIL_PORT = '2525'

EMAIL_HOST = os.environ['EMAIL_HOST']
EMAIL_HOST_USER = os.environ['EMAIL_HOST_USER']
EMAIL_HOST_PASSWORD = os.environ['EMAIL_HOST_PASSWORD']
EMAIL_PORT = os.environ['EMAIL_PORT']
EMAIL_USE_TLS = os.environ['EMAIL_USE_TLS']
EMAIL_BACKEND = os.environ['EMAIL_BACKEND']
