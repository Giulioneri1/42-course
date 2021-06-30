FROM debian:buster

RUN apt update
RUN apt upgrade -y
RUN apt install -y vim
RUN apt install -y wget
RUN apt install -y php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring php-xml

RUN wget https://wordpress.org/latest.tar.gz 
RUN tar -xvzf latest.tar.gz -C /tmp
RUN rm latest.tar.gz

RUN wget https://github.com/vrana/adminer/releases/download/v4.7.3/adminer-4.7.3.php
RUN mv adminer-4.7.3.php adminer.php
RUN mv adminer.php /tmp

COPY /tools/webpage/index.html /tmp
COPY /tools/webpage/style.css /tmp
COPY /tools/webpage/logo_white_small.png /tmp
COPY /tools/webpage/docker.png /tmp

COPY /tools/setup.sh ./
RUN chmod +x setup.sh

ENTRYPOINT ["bash", "setup.sh"]
