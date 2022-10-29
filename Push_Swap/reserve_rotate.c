/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:23:30 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/29 20:59:43 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack, int flag)
{
	t_nodo	*aux;
	t_nodo	*firts_aux;

	aux = stack->peek;
	while (aux->next->next)
		aux = aux->next;
	firts_aux = aux->next;
	firts_aux->next = stack->peek;
	stack->peek = firts_aux;
	aux->next = NULL;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack, int flag)
{
	t_nodo	*aux;
	t_nodo	*firts_aux;

	aux = stack->peek;
	while (aux->next->next)
		aux = aux->next;
	firts_aux = aux->next;
	firts_aux->next = stack->peek;
	stack->peek = firts_aux;
	aux->next = NULL;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
