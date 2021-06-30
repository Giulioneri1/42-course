FROM debian:buster

RUN apt update
RUN apt upgrade -y
RUN apt install -y nginx
RUN apt install -y openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/prova.pem -keyout /etc/nginx/ssl/prova.key -subj "/C=IT/ST=Rome/L=Rome/O=42 School/OU=gneri/CN=ssl"

COPY /tools/config etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]

