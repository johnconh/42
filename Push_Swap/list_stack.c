/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:13 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/21 20:19:57 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//La ultima posicion de la pila
t_stack *ft_stacklast (t_stack *stack)
{
	while (stack && stack->peek->sig != NULL)
		stack = stack->peek->sig;
	return (stack);
}

//Stack nuevo creado, devuelve el tamaño de la pila creada.
t_stack *ft_newstack(int nbr)
{
	t_nodo *new;
	
	new = malloc(sizeof (t_stack));
	if(!new)
		return (0);
	new -> num = nbr;
	new -> sig = NULL;
	return(new);
}

//Relleno la lista agregando los datos de la pila en la ultima posicion
void *ft_stack_full(t_stack *stack, t_stack *new)
{
	t_nodo	*ultimo;
	
	if(!new)
		return (0);
	if(!stack)
	{
		stack = new;
		return (0);	
	}
	ultimo = ft_stacklast(stack);
	ultimo -> sig = new;
	new ->peek-> sig = NULL;
	return (0);
}

size_t ft_size_list(t_stack *stack)
{
	size_t size;

	size = 0;
	while (stack)
	{
		size++;	
		stack = stack->sig;
	}
	return (size);
}