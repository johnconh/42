/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:45:24 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/05 17:04:41 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int		position;
	int		i;
	t_nodo	*pointer;

	position = 0;
	while (position < bit)
	{
		pointer = stack_a->peek;
		i = stack_a->len;
		while (pointer && i--)
		{
			if ((pointer->index >> position & 1) == 0)
			{
				pointer = pointer->next;
				ft_pb(stack_a, stack_b);
			}
			else
			{
				pointer = pointer->next;
				ft_ra(stack_a, 1);
			}
		}
		ft_stack_b_for_stack_a(stack_a, stack_b);
		position++;
	}
}

void	ft_stack_b_for_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_nodo	*pointer;

	pointer = stack_b->peek;
	while (pointer)
	{
		pointer = pointer->next;
		ft_pa(stack_a, stack_b);
	}
}
