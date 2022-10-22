/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:06:48 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/22 18:50:57 by jdasilva         ###   ########.fr       */
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
	t_nodo	*pointer;

	pointer = stack->peek;
	while (pointer->next)
	{
		temp = pointer->next;
		while(temp)
		{
			if(temp->num == pointer->num)
				return (0);
			temp = temp->next;
		}
		pointer = pointer->next;
	}
	return (1);
}

int	ft_check_list(t_stack *stack)
{
	t_nodo	*pointer;

	pointer = stack->peek;
	while(!(pointer->num < pointer->next->num) && pointer->next)
		pointer = pointer->next;
	if(pointer->next == NULL)
		return (1);
	return (0);
}
