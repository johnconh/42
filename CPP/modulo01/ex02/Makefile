NAME = Brain
SRC = main.cpp
OBJ = main.o
CXX = c++ -Wall -Werror -Wextra  -std=c++98 --pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $@
	@echo "Compilado $@"

clean:
	rm -rf $(OBJ)
	@echo "$(OBJ) borrado"

fclean: clean
	rm -rf $(NAME)
	@echo "$(NAME) borrado"

re: fclean all

.PHONY: all clean fclean re
