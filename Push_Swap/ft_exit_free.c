/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:30:38 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/15 19:50:52 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_exit_free_stack_a(t_stack *stack_a)
{
	t_stack *aux;

	while(stack_a)
	{
		aux = stack_a;
		stack_a = stack_a ->sig;
		free (aux);
	}
	write(2, "Error\n", 6);
	exit (-1);
}