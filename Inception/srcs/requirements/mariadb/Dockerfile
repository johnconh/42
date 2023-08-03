FROM debian:buster

COPY ./conf/*  /tmp/

RUN apt-get update && apt-get -y install mariadb-server \
	&&  service mysql start && chmod +x /tmp/create.sh && chmod +x /tmp/init.sh \
	&& /tmp/init.sh

EXPOSE 3306

CMD [ "mysql" ]