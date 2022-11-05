/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:30:38 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/05 17:05:31 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_free_stack(t_stack *stack, int flags)
{
	t_nodo	*aux;

	if (stack)
	{
		while (stack->peek)
		{
			aux = stack->peek;
			stack->peek = stack->peek->next;
			free (aux);
		}
		free(stack);
	}
	if (flags == 0)
		write(2, "Error\n", 6);
	exit (-1);
}

void	ft_exit_free(t_stack *stack_a, t_stack *stack_b)
{
	t_nodo	*aux;

	if (stack_a->peek)
	{
		while (stack_a->peek)
		{
			aux = stack_a->peek;
			stack_a->peek = stack_a->peek->next;
			free(aux);
		}
	}
	free(stack_a);
	if (stack_b->peek)
	{
		while (stack_b->peek)
		{
			aux = stack_b->peek;
			stack_b->peek = stack_a->peek->next;
			free(aux);
		}
	}
	free(stack_b);
	exit (0);
}

void	ft_free_stack(t_stack *stack)
{
	t_nodo	*aux;

	if (stack)
	{	
		while (stack->peek)
		{
			aux = stack->peek;
			stack->peek = stack->peek->next;
			free (aux);
		}
		free(stack);
	}
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i])
				free(str[i]);
			i++;
		}
		free(str);
	}
	write(2, "Error\n", 6);
	exit (-1);
}
