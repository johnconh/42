# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 16:26:33 by jdasilva          #+#    #+#              #
#    Updated: 2022/11/24 18:15:17 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = src/
O = objs/

NAME = so_long

CC = gcc 
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = $Smain.c

OBJS = $Omain.o

all: $(NAME)

$O:
	mkdir $@
	@echo "Carpeta OBJS creada"

$(OBJS): | $O

$(OBJS): $O%.o: $S%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
	@echo "Compilado"

clean:
	$(RM) $(OBJS) $O
	@echo "Archivos .o y carpeta OBJS elminados"

fclean : clean
	$(RM) $(NAME)
	@echo "so_long eliminado"

re: fclean all

.PHONY: all clean fclean re
