/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:06:48 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/15 19:54:21 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		while(temp->sig)
		{
			temp = temp->sig;
			if(temp->num == stack->num)
				return (0);
		}
		stack = stack->sig;
	}
	return (1);
}
