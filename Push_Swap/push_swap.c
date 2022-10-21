/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:29:03 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/21 19:56:08 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack *ft_stack_nbr(char **argv)
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
			ft_stack_full(stack_a, ft_newstack(nbr));
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
			ft_stack_full(stack_a, ft_newstack(nbr));
	}
	return (stack_a);
}

/* void ft_push_swap (t_stack **stack_a, t_stack **stack_b)
{
	size_t	listsize;
	
	if (!ft_check_list(stack_a))
		ft_exit_free_stack_a(stack_a, 1);
	listsize = ft_size_list(stack_a);
	if(listsize == 3)
		ft_stack_in_3(stack_a);
	else if(listsize == 5)
		ft_stack_in_5(stack_a, stack_b);
	else
		
} */

int main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if(!(ft_check_error(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		stack_a = ft_stack_nbr(argv);
	else if(argc > 2)
		stack_a = ft_multi_stack_nbr(argc, argv);
	if(!ft_check_doblenum_error(stack_a))
		ft_exit_free_stack_a(stack_a, 0);
	while (stack_a)
	{
		printf("stack:%d\n", stack_a->num);
		stack_a = stack_a->sig;
	}
	ft_sa(stack_a, 1);
}
