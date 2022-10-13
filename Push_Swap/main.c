/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:29:03 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/13 20:04:01 by jdasilva         ###   ########.fr       */
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
		
		if(i ++ == 1)
			stack_a = ft_newstack(nbr);	
		else
			ft_stack_full(&stack_a, ft_newstack(nbr));
	}
	return (stack_a);
}

int main (int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	
	b = NULL;
	if (argc == 2)
		a = ft_stack_nbr(argc, argv);
	else if(argc > 2)
		a = ft_multi_stack_nbr(argc, argv);
	while (a->sig)
	{
		printf("stack:%d\n", a->num);
		a = a->sig;
	}
	printf("stack:%d\n", a->num);
}