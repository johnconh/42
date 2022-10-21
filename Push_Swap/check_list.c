/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:06:48 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/21 20:08:15 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int	ft_check_error(int argc, char **argv) //verifica que si hay algo que no sea un numero de error.
{
	int i;
	int j;

	i = 0;
	while(++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if((argv[i][j] == '+' || argv[i][j] == '-') && 
				(!((argv[i][j + 1]>= '0') && (argv[i][j + 1] <= '9'))))
				return (0);
			if(!((argv[i][j] >= '0' && argv[i][j] <= '9') || 
				argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j]<= 13) 
					|| (argv[i][j] == '+' || argv[i][j] == '-')))
				return (0);
		}
	}
	return (1);

}

int	ft_check_doblenum_error(t_stack *stack) //verifica si hay un numero repetido en la lista.
{
	t_nodo	*temp;

	while (stack)
	{
		temp = stack->peek->sig;
		while(temp)
		{
			if(temp->num == stack->peek->num)
				return (0);
			temp = temp->sig;
		}
		stack = stack->peek->sig;
	}
	return (1);
}

int	ft_check_list(t_stack *stack)
{
	while(!(stack->peek->num < stack->peek->sig->num) && stack)
		stack = stack->peek->sig;
	if(stack->peek->sig == NULL)
		return (1);
	return (0);
}
