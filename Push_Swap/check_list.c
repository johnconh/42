/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:06:48 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/01 19:08:49 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//verifica que si hay algo que no sea un numero de error.
int	ft_check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{	
		j = 0;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
			&& (!((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9'))))
				return (0);
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')
				|| argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13)
					|| (argv[i][j] == '+' || argv[i][j] == '-')))
				return (0);
			j++;
		}
	}
	return (1);
}

//verifica si hay un numero repetido en la lista.
void	ft_check_doblenum_error(t_stack *stack)
{
	t_nodo	*temp;
	t_nodo	*pointer;

	pointer = stack->peek;
	while (pointer)
	{
		temp = pointer->next;
		while (temp)
		{
			if (temp->num == pointer->num)
				ft_exit_free_stack(stack, 0);
			temp = temp->next;
		}
		pointer = pointer->next;
	}
}

//verifica si la lista esta ordenada.
int	ft_check_list(t_stack *stack)
{
	t_nodo	*pointer;

	pointer = stack->peek;
	while (pointer)
	{
		if (pointer->next)
		{
			if (pointer->num > pointer->next->num)
				return (1);
		}
		pointer = pointer->next;
	}
	return (0);
}
