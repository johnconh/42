/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:29:03 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/25 19:40:36 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_stack_nbr(char *argv, t_stack *stack)
{
	long int	nbr;
	int			i;
	char		**str;

	i = -1;
	str = ft_split(argv, ' ');
	 while (str[++i])
	{
		nbr = ft_atoi(str[i]);
		ft_stack_full(stack, nbr); 
	} 
} 

void	ft_multi_stack_nbr(int argc, char **argv, t_stack *stack)
{
	int			i;

	i = 0;
	while (++i < argc)
		ft_stack_nbr(argv[i], stack);
}

void ft_push_swap (t_stack *stack_a, t_stack *stack_b)
{
	if(stack_a->len<= 3)
		ft_sort_small_stack_3(stack_a);
	else if(stack_a->len <= 5)
		ft_sort_small_stack_5(stack_a, stack_b);
	/*else
		ft_sort_big_stack(stack_a, stack_b);*/

} 

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
		ft_stack_nbr(*++argv, stack_a);
	else if(argc > 2)
		ft_multi_stack_nbr(argc, argv, stack_a);
	ft_check_doblenum_error(stack_a);
	if(!ft_check_list(stack_a))
		ft_exit_free_stack(stack_a, 1);
	ft_push_swap(stack_a, stack_b);
	while (stack_a->peek)
	{
		printf("stack A:%d\n", stack_a->peek->num);
		stack_a->peek = stack_a->peek->next;
	}
	while(stack_b->peek)
	{
		printf("stack B:%d\n", stack_b->peek->num);
		stack_b->peek = stack_b->peek->next;
	}
	printf("len:%zu", stack_a->len);
	return (0);
}
