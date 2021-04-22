# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 10:59:45 by gneri             #+#    #+#              #
#    Updated: 2021/04/19 10:59:51 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt update 
RUN apt upgrade -y
RUN apt install -y vim
RUN apt install -y wget
RUN apt install -y nginx
RUN apt install -y mariadb-server
RUN apt install -y php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring php-xml

COPY /srcs/default_autoindex_on /tmp
COPY /srcs/default_autoindex_off /tmp
COPY /srcs/index.html /var/www/html/index.nginx-debian.html
COPY /srcs/style.css /var/www/html
COPY /srcs/logo_white_small.png /var/www/html
COPY /srcs/docker.png /var/www/html

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz
RUN tar -zxvf phpMyAdmin-5.1.0-all-languages.tar.gz && rm -rf phpMyAdmin-5.1.0-all-languages.tar.gz
RUN mv phpMyAdmin-5.1.0-all-languages /var/www/html/phpmyadmin
COPY /srcs/config.inc.php /var/www/html/phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz 
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
RUN mv wordpress /var/www/html/wordpress
RUN rm /var/www/html/wordpress/wp-config-sample.php
COPY /srcs/wp-config.php /var/www/html/wordpress/wp-config.php

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/prova.pem -keyout /etc/nginx/ssl/prova.key -subj "/C=IT/ST=Rome/L=Rome/O=42 School/OU=gneri/CN=ssl"

RUN chown -R www-data /var/www/*
RUN chmod -R 755 /var/www/*

EXPOSE 80 443

COPY /srcs/*.sh ./
RUN chmod +x mysql.sh autoindex.sh
RUN sh /mysql.sh
CMD bash init.sh