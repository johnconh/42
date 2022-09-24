# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 13:51:46 by jdasilva          #+#    #+#              #
#    Updated: 2022/09/24 21:13:26 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_prinft.c \
 		ft_putchar.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putunbr.c \
		ft_strlen.c
		
CC = gcc		
FLAGS = -Wall -Werror -Wextra
AR = ar rc
OBJS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	echo "Compilado"

#$(OBJ) : %.o:%.c
#(CC) $(FLAGS) -c $(SRC)
	
clean:
	rm -rf $(OBJS)
	echo "Archivos .o elminados"

fclean: clean
	rm -rf $(NAME)
	echo "Archivos .o .a elimiandos"

re: fclean all

.PHONY: all clean fclean re