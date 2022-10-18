/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:06:48 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/18 17:15:25 by jdasilva         ###   ########.fr       */
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
	t_stack	*temp;
	
	while (stack)
	{
		temp = stack->sig;
		while(temp)
		{
			if(temp->num == stack->num)
				return (0);
			temp = temp->sig;
		}
		stack = stack->sig;
	}
	return (1);
}

