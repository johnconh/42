/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:29:03 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/15 19:50:36 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack *ft_stack_nbr(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nbr;
	int			i;
	char		**str;

	i = 0;
	str = ft_split(argv[1], ' ');
	while (str[i])
	{
		nbr = ft_atoi(str[i]);
		if (!nbr)
		{
			write(2, "Error\n", 6);
			exit (-1);
		}
		if(i ++ == 0)
			stack_a = ft_newstack(nbr);	
		else
			ft_stack_full(&stack_a, ft_newstack(nbr));
	}
	return (stack_a);
}

t_stack	*ft_multi_stack_nbr(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nbr;
	int			i;

	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (!nbr)
		{
			write(2, "Error\n", 6);
			exit (-1);
		}
		if(i ++ == 1)
			stack_a = ft_newstack(nbr);	
		else
			ft_stack_full(&stack_a, ft_newstack(nbr));
	}
	return (stack_a);
}

int main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	
	stack_b = NULL;
	if (argc == 2)
		stack_a = ft_stack_nbr(argc, argv);
	else if(argc > 2)
		stack_a = ft_multi_stack_nbr(argc, argv);
 	if(!ft_check_error(stack_a))
		ft_exit_free_stack_a(stack_a);
	while (stack_a->sig)
	{
		printf("stack:%d\n", stack_a->num);
		stack_a = stack_a->sig;
	}
	printf("stack:%d\n", stack_a->num);
}