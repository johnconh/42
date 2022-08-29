/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:57:13 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/06 21:33:12 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int main (void)
{
	int a;
	int b;
	int div;
	int mod;
	
	a = 10;
	b = 2;
	
	ft_div_mod(a, b, &div, &mod);
	printf("numero_a:%d\nnumero_b:%d\ndivision:%d\ncoficiente:%d\n", a, b, div, mod);
}
