/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:08:03 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/21 19:59:13 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
typedef struct s_nodo
{ 
	int 			num;
	struct s_nodo	*sig;
}t_nodo;

typedef struct s_stack
{
	t_nodo *peek;
	size_t	len;
}t_stack;

//##### STACK #######
void	*ft_stack_full(t_stack *stack, t_stack *new);
t_stack *ft_newstack(int nbr);
t_stack *ft_stacklast (t_stack *stack);
//##### CHECK ERROR###
int		ft_check_error(int argc, char  **argv);
void	ft_exit_free_stack_a(t_stack *stack_a, int flags);
int		ft_check_doblenum_error(t_stack *stack);
int		ft_check_list(t_stack *stack);
//##### LIBFT #######
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
//##### OPERATOR #####
void	ft_sa(t_stack *stack, int flag);
void	ft_sb(t_stack *stack, int flag);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack	**stack, int flag);
void	ft_rb(t_stack	**stack, int flag);
void	ft_rr(t_stack	**stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack, int flag);
void	ft_rrb(t_stack **stack, int flag);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
#endif
