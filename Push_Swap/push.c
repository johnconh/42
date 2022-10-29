/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:15:24 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/29 20:59:01 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_nodo	*aux;

	if (!stack_b)
		return ;
	aux = stack_b->peek->next;
	stack_b->peek->next = stack_a->peek;
	stack_a->peek = stack_b->peek;
	stack_b->peek = aux;
	stack_a->len ++;
	stack_b->len --;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_nodo	*aux;

	if (!stack_a)
		return ;
	aux = stack_a->peek->next;
	stack_a->peek->next = stack_b->peek;
	stack_b->peek = stack_a->peek;
	stack_a->peek = aux;
	stack_a->len --;
	stack_b->len ++;
	write(1, "pb\n", 3);
}
