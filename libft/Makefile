# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 21:10:17 by jdasilva          #+#    #+#              #
#    Updated: 2022/09/14 14:16:41 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_strlen.c ft_bzero.c ft_toupper.c ft_tolower.c\
		ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
		ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
		ft_strnstr.c ft_substr.c ft_strjoin.c ft_strtrim.c\
		ft_atoi.c \
		ft_calloc.c ft_strdup.c\
		
OBJS = $(SRC:.c=.o)

#BONUS_SRC =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
			ft_lstnew_bonus.c ft_lstsize_bonus.c \
			
#BONUS_OBJS = $(BONUS_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBC = ar rcs

%.o: %.c
		$(CC) -c $(CFLAGS) $^


all : $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $@ $^

#bonus: $(BONUS_OBJS)
	$(LIBC) $(NAME) $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean