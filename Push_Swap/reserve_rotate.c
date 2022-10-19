/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:23:30 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/19 14:05:32 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stack, int flag)
{
	t_stack	*aux;
	t_stack *firts_aux;
	
	aux = *stack;
	while(aux->sig->sig !=NULL)
		aux = aux->sig;
	firts_aux = aux->sig;
	firts_aux->sig = *stack;
	*stack = firts_aux;
	aux->sig = NULL;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack, int flag)
{
	t_stack	*aux;
	t_stack *firts_aux;
	
	aux = *stack;
	while(aux->sig->sig !=NULL)
		aux = aux->sig;
	firts_aux = aux->sig;
	firts_aux->sig = *stack;
	*stack = firts_aux;
	aux->sig = NULL;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}