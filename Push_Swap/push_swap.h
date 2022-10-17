/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:08:03 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/17 19:25:25 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
typedef struct s_stack
{ 
	int 			num;
	struct s_stack	*sig;
}t_stack;

// ##### STACK #####
void	*ft_stack_full(t_stack **stack, t_stack *new);
t_stack *ft_newstack(int nbr);
t_stack *ft_stacklast (t_stack *stack);
//##### CHECK ERROR##
int		ft_check_error(int argc, char  **argv);
void	ft_exit_free_stack_a(t_stack *stack_a);
int		ft_check_doblenum_error(t_stack *stack);
//##### LIBFT ######
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
#endif
