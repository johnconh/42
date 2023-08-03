FROM debian:buster

COPY ./conf/setup.sh /tmp

RUN apt-get update && apt -y install curl wget netcat tar \
	&& apt install -y php php-fpm php-mysql php-gd php-xmlphp-curl \
	&& curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar  && mv -f wp-cli.phar /usr/local/bin/wp \
	&& chmod +x /tmp/setup.sh

COPY ./conf/www.conf  /etc/php/7.3/fpm/pool.d/

EXPOSE 9000


CMD [ "sh -c", "./tmp/setup.sh && /usr/sbin/php-fpm7.3 -F" ]