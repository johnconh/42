/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:13 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/31 19:47:18 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Cabeza nueva creada.
t_stack	*ft_newpeek(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->peek = NULL;
	new->len = 0;
	return (new);
}

//Nodo nuevo creado, devuelve el tamaño de la pila creada.
t_nodo	*ft_newnodo(int nbr)
{
	t_nodo	*new;

	new = (t_nodo *)malloc(sizeof (t_nodo));
	if (!new)
		return (0);
	new -> num = nbr;
	new -> next = NULL;
	return (new);
}

//Relleno la lista agregando los datos de la pila en la ultima posicion.
void	*ft_stack_full(t_stack *stack, int nbr)
{
	t_nodo	*nodo;
	t_nodo	*pointer;

	nodo = ft_newnodo(nbr);
	if (stack->peek)
	{
		pointer = stack->peek;
		while (pointer->next)
			pointer = pointer->next;
		pointer->next = nodo;
	}
	else
		stack->peek = nodo;
	stack->len++;
	return (0);
}
