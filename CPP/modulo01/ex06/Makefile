NAME = harlFilter
FILES = main Harl
SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

CXX = c++ -Wall -Werror -Wextra  -std=c++98 --pedantic -fsanitize=address -g3

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