/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:50:19 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/29 21:00:18 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack	*stack, int flag)
{
	t_nodo	*aux;
	t_nodo	*last_aux;

	aux = stack->peek;
	stack->peek = stack->peek->next;
	last_aux = stack->peek->next;
	while (last_aux->next != NULL)
		last_aux = last_aux->next;
	last_aux->next = aux;
	aux->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack	*stack, int flag)
{
	t_nodo	*aux;
	t_nodo	*last_aux;

	aux = stack->peek;
	stack->peek = stack->peek->next;
	last_aux = stack->peek->next;
	while (last_aux->next != NULL)
		last_aux = last_aux->next;
	last_aux->next = aux;
	aux->next = NULL;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	write(1, "rr\n", 3);
}
