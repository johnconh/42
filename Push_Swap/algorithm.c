/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:17:34 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/28 19:54:59 by jdasilva         ###   ########.fr       */
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
	t_nodo	*maxnum;
	t_nodo	*minnum;
	int		pos;

	maxnum = ft_num_max_or_min(stack_a, 1);
	pos = ft_position_max_or_min(stack_a, maxnum);
	ft_first_position(stack_a, pos);
	ft_pb(stack_a, stack_b);
	if(stack_a->len == 4)
	{
		minnum = ft_num_max_or_min(stack_a, 0);
		pos = ft_position_max_or_min(stack_a, minnum);
		ft_first_position(stack_a, pos);
		ft_pb(stack_a, stack_b);
		if (ft_check_list(stack_a) && stack_a->len == 3)
			ft_sort_small_stack_3(stack_a);
		ft_pa(stack_a, stack_b);
	}else if(stack_a->len == 3)
		if (ft_check_list(stack_a) && stack_a->len == 3)
			ft_sort_small_stack_3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a, 1);
}

void	ft_sort_big_stack(t_stack *stack_a)
{
	ft_assign_index(stack_a);
	
}

void ft_assign_index(t_stack *stack)
{
	int		i;
	t_nodo	*minnum;
	t_nodo	*ptr; //ptr = pointer.
	t_nodo 	*ptrnum;

	i = 0;
	minnum = ft_num_max_or_min(stack, 0);
	minnum->index = i;
	ptr = stack->peek;
	ptrnum = ptr;
	
	while(ptr->num > minnum->num)
	{
		while(ptr)
		{
			if(ptr->num < ptrnum->num && ptr->num > minnum->num)
				ptrnum = ptr;
			ptr = ptr->next;
		}
		ptrnum->index = ++i;
		minnum = ptrnum;
		ptr = stack->peek;
		ptrnum = ptr;
	}
}