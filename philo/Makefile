# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 16:57:36 by jdasilva          #+#    #+#              #
#    Updated: 2023/01/10 19:36:16 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = src/
O = obj/

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = $Smain.c $Sft_destroy.c $Sft_init_list.c $Sft_init_philo.c\
	$Sft_philo_thread.c $Sphilo_utils.c $Sstatus_print.c
OBJS = $Omain.o $Oft_destroy.o $Oft_init_list.o $Oft_init_philo.o\
	$Oft_philo_thread.o $Ophilo_utils.o $Ostatus_print.o

NORMAL_COLOR = \x1b[m
RED = \x1b[31m
GREEN = \x1b[32m

all: $(NAME)

$O:
	mkdir $@
	@echo "$(GREEN)Carpeta obj creada$(NORMAL_COLOR)"

$(OBJS) : $O%.o: $S%.c | $O
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $^ -o $@
			@echo "$(GREEN)Compilado$(NORMAL_COLOR)"
clean:
		$(RM) $(OBJS) $O
		@echo "$(RED)Archivos .o eliminados$(NORMAL_COLOR)"
fclean: clean
		$(RM) $(NAME)
		@echo "$(RED)Archivo philo eliminado$(NORMAL_COLOR)"
re: fclean all

.PHONY: all clean fclean re