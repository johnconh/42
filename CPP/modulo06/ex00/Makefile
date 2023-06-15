NAME = convert
FILES = main convert
SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

CXX = clang++ -Wall -Werror -Wextra  -std=c++98 --pedantic
SANI_CXX = $(CXX) -g3 -fsanitize=address

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

sani: CXX := $(SANI_CXX)
sani: all

.PHONY: all clean fclean re sani