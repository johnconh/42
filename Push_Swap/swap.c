/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:40:23 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/18 18:12:59 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack)
{
	t_stack	*aux;

	aux = (*stack)->num;
	(*stack)->num = (*stack)->sig->num;
	(*stack)->sig->num = aux;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack)
{
	t_stack	*aux;

	aux = (*stack)->num;
	(*stack)->num = (*stack)->sig->num;
	(*stack)->sig->num = aux;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	write(1, "ss\n", 3);
}
