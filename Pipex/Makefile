# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 16:33:38 by jdasilva          #+#    #+#              #
#    Updated: 2022/11/14 20:16:50 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = mandatory/src/
O = mandatory/objs/

NAME = pipex

SRC = $Spipex.c $Spipex_utils.c $Sft_strncmp.c $Sft_strlen.c \
	$Sft_strlcpy.c $Sft_split.c $Sft_strjoin.c $Sft_strlcat.c

OBJS = $Opipex.o $Opipex_utils.o $Oft_strncmp.o $Oft_strlen.o \
	$Oft_strlcpy.o $Oft_split.o $Oft_strjoin.o $Oft_strlcat.o

CC = gcc -Wall -Werror -Wextra -g3

all: $(NAME)

$O:
	mkdir $@
	@echo "Carpeta objs creada"

$(OBJS): | $O

$(OBJS): $O%.o: $S%.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $^ -o $@
		@echo "Compilado"
clean:
	rm -rf $(OBJS) $O
	@echo "Archivos . o eliminados"
fclean: clean
	rm -rf $(NAME)
	@echo "Archivo pipex eliminado"
re: fclean all

.PHONY: all clean fclean re