/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:15:24 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/21 16:18:57 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *aux;

	if(!stack_b)
		return ;
	aux = (*stack_b)->sig;
	(*stack_b)->sig = *stack_a;
	*stack_a = *stack_b;
	*stack_b = aux;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *aux;

	if(!stack_a)
		return ;
	aux = (*stack_a)->sig;
	(*stack_a)->sig = *stack_b;
	*stack_b = *stack_a;
	*stack_a = aux;
	write(1, "pb\n", 3);
}
