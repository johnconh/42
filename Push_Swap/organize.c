/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:41:20 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/29 20:54:24 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Selecciona cual es el numero maxo o min de la pila.
t_nodo	*ft_num_max_or_min(t_stack *stack, int type)
{
	t_nodo	*pointer;
	t_nodo	*select;

	pointer = stack->peek;
	select = pointer;
	while (pointer)
	{
		if (pointer->num > select->num && type == 1)
			select = pointer;
		else if (pointer->num < select->num && type == 0)
			select = pointer;
		pointer = pointer->next;
	}
	return (select);
}

//Me indica la posicion del numero max o min de la pila.
int	ft_position_max_or_min(t_stack *stack, t_nodo *num)
{
	t_nodo	*pointer;
	int		pos;

	pos = 1;
	pointer = stack->peek;
	while (pointer)
	{
		if (pointer->num == num->num)
			break ;
		pos++;
		pointer = pointer->next;
	}
	return (pos);
}

//Coloca el numero en primera posicion dependiendo de su puesto en la pila.
void	ft_first_position(t_stack *stack, int pos)
{
	if (pos == 2)
		ft_sa(stack, 1);
	else if (pos == 3)
	{
		ft_ra(stack, 1);
		ft_sa(stack, 1);
	}
	else if (pos == 4 && stack->len == 5)
	{
		ft_rra(stack, 1);
		ft_rra(stack, 1);
	}
	else if (pos == 5 || pos == 4)
		ft_rra(stack, 1);
}
