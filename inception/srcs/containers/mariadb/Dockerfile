FROM debian:buster

RUN apt update
RUN apt install -y vim 

COPY /tools/50-server.cnf /tmp
COPY /tools/setup.sh ./
RUN chmod +x setup.sh
RUN mkdir -p mariadb

CMD bash ./setup.sh