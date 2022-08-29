/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:55:05 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/06 21:34:41 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main (void)
{
	int a;
	int b;

	a = 10;
	b = 2;

	printf("a = %d\nb =%d\n",a ,b);
	ft_ultimate_div_mod(&a, &b);
	printf ("Resultado division =%d\nResto =%d\n", a, b);	
}