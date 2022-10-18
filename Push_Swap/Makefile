# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:00:06 by jdasilva          #+#    #+#              #
#    Updated: 2022/10/18 17:33:31 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =push_swap

SRC = push_swap.c check_list.c ft_atoi.c ft_exit_free.c ft_split.c \
	list_stack.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:%.c=%.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilado"

clean:
	rm -rf $(OBJS)
	@echo "Archivos .o eliminados"

fclean: clean
	rm -rf $(NAME)
	@echo "Archivo push_swap eliminado"
	
re: fclean all

.PHONY: all clean fclean re