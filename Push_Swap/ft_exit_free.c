/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:30:38 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/29 20:50:30 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_free_stack(t_stack *stack, int flags)
{
	t_nodo	*aux;
	t_nodo	*pointer;

	pointer = stack->peek;
	while (pointer->next)
	{
		aux = pointer->next;
		pointer->next = pointer->next->next;
		free (aux);
	}
	free(stack);
	if (flags == 0)
		write(2, "Error\n", 6);
	exit (-1);
}

void	ft_exit_free(t_stack *stack_a, t_stack *stack_b)
{
	t_nodo	*aux;

	if (stack_a->peek)
	{
		while (stack_a->peek->next)
		{
			aux = stack_a->peek->next;
			stack_a->peek->next = stack_a->peek->next->next;
			free(aux);
		}
	}
	free(stack_a);
	if (stack_b->peek)
	{
		while (stack_b->peek->next)
		{
			aux = stack_b->peek->next;
			stack_b->peek->next = stack_a->peek->next->next;
			free(aux);
		}
	}
	free(stack_b);
	exit (0);
}
