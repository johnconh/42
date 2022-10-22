/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:29:03 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/22 21:07:53 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_stack_nbr(char **argv, t_stack *stack)
{
	long int	nbr;
	int			i;
	char		**str;

	i = -1;
	str = ft_split(argv[1], ' ');
	 while (str[++i])
	{
		nbr = ft_atoi(str[i]);
		ft_stack_full(stack, nbr); 
	}
} 

void	*ft_multi_stack_nbr(int argc, char **argv, t_stack *stack)
{
	long int	nbr;
	int			i;

	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		ft_stack_full(stack, nbr);
		i++;
	}
	return (0);
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
	if(!(ft_check_error(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = ft_newpeek();
	stack_b = ft_newpeek();
	if (argc == 2)
		ft_stack_nbr(argv, stack_a);
	else if(argc > 2)
		ft_multi_stack_nbr(argc, argv, stack_a);
	if(!ft_check_doblenum_error(stack_a))
		ft_exit_free_stack_a(stack_a, 0);
	ft_sa(stack_a, 1);
	while (stack_a->peek)
	{
		printf("stack:%d\n", stack_a->peek->num);
		stack_a->peek = stack_a->peek->next;
	}
	return (0);
}
