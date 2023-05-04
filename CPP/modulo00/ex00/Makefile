NAME = megaphone
SRC = mehaphone.cpp
OBJ = megaphone.o
CC = c++ -Wall -Werror -Wextra  -std=c++98 --pedantic

.SILENT:

all: $(NAME)

megaphone.o: megaphone.cpp
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $@
	@echo "Compilado $@"

clean:
	rm -rf $(OBJ)
	@echo "$(OBJ) borrado"

fclean: clean
	rm -rf $(NAME)
	@echo "$(NAME) borrado"

re: fclean all

.PHONY: all clean fclean re
