NAME = Inception
START_PATH = ./srcs/

start:
	@ cd $(START_PATH) && sudo docker-compose up -d && sudo sh domain.sh;
	
stop:
	@ cd $(START_PATH) && sudo docker-compose down; 

clean: stop
	@ cd $(START_PATH) && sudo docker system prune -a -f; 

destroy: clean
	@ sudo docker volume rm $$(sudo docker volume ls -q);
	@ sudo rm -Rf ~/data/;

all: destroy start

re: clean start

.PHONY: start stop clean destroy all