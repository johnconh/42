/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:17:33 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/29 20:33:10 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_min_index(t_stack *stack)
{
	int		i;
	t_nodo	*min;
	t_nodo	*ptr;
	t_nodo	*ptrnum;

	i = 0;
	min = ft_num_max_or_min(stack, 0);
	min->index = i;
	ptr = stack->peek;
	ptrnum = ptr;
	while (ptr->num > min->num)
	{
		while (ptr)
		{
			if (ptr->num < ptrnum->num && ptr->num > min->num)
				ptrnum = ptr;
			ptr = ptr->next;
		}
		ptrnum->index = ++i;
		min = ptrnum;
		ptr = stack->peek;
		ptrnum = ptr;
	}
}

void	ft_assign_max_index(t_stack *stack)
{
	int		i;
	t_nodo	*max;
	t_nodo	*ptr;
	t_nodo	*ptrnum;

	i = stack->len - 1;
	max = ft_num_max_or_min(stack, 1);
	max->index = i;
	ptr = stack->peek;
	ptrnum = ptr;
	while (ptr->num < max->num)
	{
		while (ptr)
		{
			if (ptr->num > ptrnum->num && ptr->num < max->num)
				ptrnum = ptr;
			ptr = ptr->next;
		}
		ptrnum->index = --i;
		max = ptrnum;
		ptr = stack->peek;
		ptrnum = ptr;
	}
}

void	ft_assign_index(t_stack *stack)
{
	ft_assign_min_index(stack);
	ft_assign_max_index(stack);
}
