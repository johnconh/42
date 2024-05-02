# --- Makefile structure ---

## Program Name:
NAME	=	ft_transcendence

## Folder Structure:
LOGO_FILE		=	./src/tools/logo.txt
COMPOSE_FILE	=	./src/docker-compose.yml
STORAGE_INIT	=	./src/tools/setup_host_storage.sh
STORAGE_REMOVE	=	./src/tools/remove_storage.sh

# *************************************************************************** #

# --- Makefile Extras ---

## Colors:
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# *************************************************************************** #

# --- Makefile instructions ---

all:
		@clear
		@echo "$(CYAN)"
		@cat $(LOGO_FILE)
		@echo
		@echo
		@echo "           | -------------- | ------------------------------------------------------------------- |"
		@echo "           |      CMD       |                             DESCRIPTION                             |"
		@echo "           | -------------- | ------------------------------------------------------------------- |"
		@echo "           |   make         |   Informartion on make arguments (this prompt)                      |"
		@echo "           |   make up      |   Run ft_transcendence Project                                      |"
		@echo "           |   make down    |   Stop ft_transcendence Project                                     |"
		@echo "           |   make clean   |   Clean all docker containers, volumes and networks                 |"
		@echo "           |   make fclean  |   Clean and remove all docker images                                |"
		@echo "           |   make re      |   make fclean and then make up                                      |"
		@echo "           |   make ls      |   Informartion on docker images, containers, volumes and networks   |"
		@echo "           |   make log     |   Logs from all the containers                                      |"
		@echo "           |   $(RED)make purge  $(CYAN) |   $(RED)Deletes all permanent storage$(CYAN)                                     |"
		@echo "           | -------------- | ------------------------------------------------------------------- |"
		@echo "           |   make admin   |   Creates a admin user (the containers needs to be running)         |"
		@echo "           | -------------- | ------------------------------------------------------------------- |"
		@echo
		@echo "$(DEF_COLOR)"

up:
		@sh $(STORAGE_INIT)
		@if [ -n "$$(docker-compose -f $(COMPOSE_FILE) ps -q)" ]; then \
			echo "$(RED)Error: $(NAME) compose file is already running$(DEF_COLOR)"; \
		else \
			echo "$(GREEN)Initializing $(NAME) compose file... $(DEF_COLOR)"; \
			docker-compose -f $(COMPOSE_FILE) --env-file src/.env up -d; \
			echo "";\
			echo "$(BLUE)Access the following links:$(DEF_COLOR)"; \
			echo "$(BLUE) - https://localhost/ $(DEF_COLOR)"; \
		fi

admin:
		@if [ -n "$$(docker-compose -f $(COMPOSE_FILE) ps -q)" ]; then \
			echo "$(YELLOW)Creating Superuser for backend... $(DEF_COLOR)"; \
			docker exec -it backend sh -c "python /backend/manage.py createsuperuser"; \
			echo "$(GREEN)Superuser for backend created$(DEF_COLOR)"; \
		else \
			echo "$(RED)Error: $(NAME) compose file is not running$(DEF_COLOR)"; \
		fi
down:
		@if [ -n "$$(docker-compose -f $(COMPOSE_FILE) ps -q)" ]; then \
			echo "$(GREEN)Stopping $(NAME) compose file... $(DEF_COLOR)"; \
			docker-compose -f $(COMPOSE_FILE) down; \
		else \
			echo "$(RED)Error: $(NAME) compose file is not running$(DEF_COLOR)"; \
		fi

clean:	down
		@if [ -n "$$(docker ps -q)" ]; then \
			docker stop $$(docker ps -q); \
			docker rm $$(docker ps -qa); \
		fi
		@echo "$(GREEN)All running containers stopped and removed.$(DEF_COLOR)"
		@if [ -n "$$(docker volume ls -q)" ]; then \
			docker volume rm $$(docker volume ls -q); \
		fi
		@echo "$(GREEN)All docker volumes removed.$(DEF_COLOR)"
		@if [ -n "$$(docker network ls --filter type=custom -q)" ]; then \
			docker network rm $$(docker network ls --filter type=custom -q); \
		fi
		@echo "$(GREEN)All docker networks removed.$(DEF_COLOR)"

fclean:	clean
		@if [ -n "$$(docker images -q)" ]; then \
			docker rmi -f $$(docker images -q); \
		fi
		@echo "$(GREEN)All docker images removed.$(DEF_COLOR)"
		@make ls --no-print-directory

ls:
		@echo
		@echo "$(YELLOW)SUMMARY OF DOCKER IMAGES, CONTAINERS, VOLUMES AND NETWORKS:$(DEF_COLOR)"
		@echo "$(YELLOW)-----------------------------------------------------------$(DEF_COLOR)"
		@echo "$(YELLOW)  - DOCKER IMAGES LIST:$(DEF_COLOR)"
		@docker images
		@echo
		@echo "$(YELLOW)  - DOCKER CONTAINERS LIST (ALL):$(DEF_COLOR)"
		@docker ps -a
		@echo
		@echo "$(YELLOW)  - DOCKER VOLUMES LIST:$(DEF_COLOR)"
		@docker volume ls
		@echo
		@echo "$(YELLOW)  - DOCKER NETWORK LIST:$(DEF_COLOR)"
		@docker network ls --filter type=custom
		@echo

purge:	fclean
		@echo "$(RED)Removing permanent storage and docker cache!$(DEF_COLOR)"
		@docker system prune -a -f
		@find . | grep __pycache__ | xargs rm -rf
		@find . -path '*/migrations/*' ! -name '__init__.py' -type f -delete
		@sh $(STORAGE_REMOVE)

log:
		@docker-compose -f $(COMPOSE_FILE) logs

re:		fclean up

.PHONY: all up down clean ls fclean re log purgedb
