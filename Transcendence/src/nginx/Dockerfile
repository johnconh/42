FROM nginx:latest

COPY /tools/selfsigned.crt /tmp/selfsigned.crt
COPY /tools/selfsigned.key /tmp/selfsigned.key

RUN apt-get update && apt-get install -y procps
RUN mkdir -p /home/app/staticfiles
