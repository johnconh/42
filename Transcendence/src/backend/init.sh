python /backend/manage.py makemigrations
python /backend/manage.py migrate
python /backend/manage.py runserver 0.0.0.0:61001
# gunicorn conf.wsgi:application --bind 0.0.0.0:61001 # to be changed for channels??