
FROM debian:buster

RUN apt-get update && apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/nginx/ssl/jdasilva.key \
	-out /etc/nginx/ssl/jdasilva.crt \
	-subj "/CN=jdasilva.42.fr"

COPY ./conf/nginx.conf /etc/nginx/conf.d
COPY ./tools/index.html /usr/share/nginx/html/

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]