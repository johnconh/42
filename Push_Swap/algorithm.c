/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:17:34 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/25 21:20:46 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_stack_3(t_stack *stack)
{
	if(stack->peek->num > stack->peek->next->num)
	{
		if(stack->peek->next->num < stack->peek->next->next->num && 
			stack->peek->num > stack->peek->next->next->num)
			ft_ra(stack, 1);
		else
			ft_sa(stack, 1);
		if(ft_check_list(stack) == 1)
			ft_rra(stack, 1);
	}
	else if (stack->peek->num < stack->peek->next->num)
	{
		if(stack->peek->next->num > stack->peek->next->next->num && 
			stack->peek->num > stack->peek->next->next->num)
			ft_rra(stack, 1);
		else
			ft_sa(stack, 1);
		if(ft_check_list(stack) == 1)
			ft_ra (stack, 1);
	}
}

void	ft_sort_small_stack_5(t_stack *stack_a, t_stack *stack_b)
{
	t_nodo *pointer;

	
}