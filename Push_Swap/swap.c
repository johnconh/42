/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:40:23 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/29 21:00:53 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack, int flag)
{
	t_nodo	*aux;

	if (!stack->peek || !stack->peek->next)
		return ;
	aux = stack->peek;
	stack->peek = aux->next;
	aux->next = aux->next->next;
	stack->peek->next = aux;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack, int flag)
{
	t_nodo	*aux;

	aux = NULL;
	if (!stack->peek || !stack->peek->next)
		return ;
	aux = stack->peek;
	stack->peek = aux->next;
	aux->next = aux->next->next;
	stack->peek->next = aux;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	write(1, "ss\n", 3);
}
