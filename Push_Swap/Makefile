# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:00:06 by jdasilva          #+#    #+#              #
#    Updated: 2022/11/05 17:03:37 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =push_swap

SRC = push_swap.c check_list.c ft_atoi.c ft_exit_free.c list_stack.c ft_split.c\
		swap.c push.c rotate.c reserve_rotate.c algorithm.c organize.c \
			ft_assign_index.c ft_radix_sort.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
VAL = -g3
OBJS = $(SRC:%.c=%.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Compilado"

clean:
	rm -rf $(OBJS)
	@echo "Archivos .o eliminados"

fclean: clean
	rm -rf $(NAME)
	@echo "Archivo push_swap eliminado"
	
re: fclean all

val: $(OBJS)
	$(CC) $(CFLAGS) $(VAL) $^ -o $(NAME)

.PHONY: all clean fclean re