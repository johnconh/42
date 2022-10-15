/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:13 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/15 16:38:37 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//La ultima posicion de la pila
t_stack *ft_stacklast (t_stack *stack)
{
	while (stack && stack->sig != NULL)
		stack = stack->sig;
	return (stack);
}

//Stack nuevo creado, devuelve el tamaño de la pila creada.
t_stack *ft_newstack(int nbr)
{
	t_stack *new;
	
	new = malloc(sizeof (t_stack));
	if(!new)
		return (0);
	new -> num = nbr;
	new -> sig = NULL;
	return(new);
}

//Relleno la lista agregando los datos de la pila en la ultima posicion
void *ft_stack_full(t_stack **stack, t_stack *new)
{
	t_stack	*ultimo;
	
	if(!new)
		return (0);
	if(!*stack)
	{
		*stack = new;
		return (0);	
	}
	ultimo = ft_stacklast(*stack);
	ultimo -> sig = new;
	new -> sig = NULL;
	return (0);
}