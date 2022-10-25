/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:30:38 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/25 18:09:17 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_exit_free_stack(t_stack *stack, int flags)
{
	t_nodo *aux;
	t_nodo *pointer;

	pointer = stack->peek;
	while(pointer->next)
	{
		aux = pointer->next;
		pointer->next = pointer->next->next;
		free (aux);
	} 
	free(stack);
	if(flags == 0)
		write(2, "Error\n", 6);
	exit (-1);
}
