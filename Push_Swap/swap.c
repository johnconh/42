/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:40:23 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/21 20:24:24 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack, int flag)
{
	t_nodo	*aux;

	if(!stack || !stack->peek->sig)
		return ;
	printf("sa:%d\n", stack->num);
	aux = stack->peek;
	stack->peek = stack->peek->sig;
	stack->peek->sig = aux;
	if(flag == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack, int flag)
{
	t_stack	*aux;

	aux = NULL;
	if(!stack->num || !stack->sig->num)
		return ;
	aux->num = stack->num;
	stack->num = stack->sig->num;
	stack->sig->num = aux->num;
	if(flag == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	write(1, "ss\n", 3);
}
