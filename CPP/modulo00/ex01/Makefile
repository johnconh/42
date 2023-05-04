NAME = Phonebook
FILES = Contact Phonebook main
SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

CC = c++ -Wall -Werror -Wextra  -std=c++98 --pedantic

.SILENT:

all: $(NAME)

%.o: %.cpp
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