# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 16:26:33 by jdasilva          #+#    #+#              #
#    Updated: 2022/12/01 19:33:36 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = src/
O = objs/

NAME = so_long

CC = gcc 
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = $Smain.c, $Sget_next_line.c, $Sget_next_line_utils.c, $Sget_map.c\
	$Scheck_map.c $Sexit_free.c $Skey_hook.c $Splaces_imgd.c

OBJS = $Omain.o, $Oget_next_line.o, $Oget_next_line_utils.o, $Oget_map.o\
	$Ocheck_map.o $Oexit_free.o $Okey_hook.o $Oplaces_imgd.o

all: $(NAME)

$O:
	mkdir $@
	@echo "Carpeta OBJS creada"

$(OBJS): | $O

$(OBJS): $O%.o: $S%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C mlx 2>logs
	$(RM) logs
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
	@echo "Compilado"

clean:
	$(RM) $(OBJS) $O
	$(RM) mlx/*.o
	@echo "Archivos .o y carpeta OBJS elminados"

fclean : clean
	$(RM) $(NAME)
	$(RM) mlx/libmlx.a
	@echo "so_long eliminado"

re: fclean all

.PHONY: all clean fclean re
