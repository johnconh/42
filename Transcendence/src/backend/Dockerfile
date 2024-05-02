# Use the penultimate version of alpine as Base Image:
FROM python:3.12.0-alpine3.18

# Print to logs correctly from python:
ENV PYTHONUNBUFFERED 1
ENV PYTHONDONTWRITEBYTECODE 1

# Update the alpine image and all the packages on it:
RUN apk update && apk upgrade

# Generate folder for the backend and copy required installation backend files:
WORKDIR /backend
COPY /backend/requirements.txt .
COPY /tools/selfsigned.crt /tmp/selfsigned.crt
COPY /tools/selfsigned.key /tmp/selfsigned.key

# Install required additional packages:
RUN apk add build-base
RUN apk add libffi-dev
RUN pip install --upgrade pip
RUN pip install --no-cache-dir -r /backend/requirements.txt

# Expose the https port for accessing the server from the web browser:
EXPOSE 61001

# Start django server:
CMD ["sh", "init.sh"]
