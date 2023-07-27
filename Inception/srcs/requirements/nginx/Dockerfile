
FROM debian:buster

RUN apt-get update && apt-get install -y nginx openssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/nginx/jdasilva.key \
	-out /etc/nginx/jdasilva.crt \
	-subj "/CN=jdasilva.42.fr"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./tools/index.html /usr/share/nginx/html/

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]