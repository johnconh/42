/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:29:30 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/06 21:35:08 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int main (void)
{
	int i;
	int *tab;


	tab[0] = 12;
	tab[1] = 2;
	tab[2] = 76;
	tab[3] = 45;
	tab[4] = 22;
	tab[5] = 10;

	ft_sort_int_tab(tab, 6);
	i = 0;
	while ( i < 6)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}