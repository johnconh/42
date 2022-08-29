/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:33:19 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/06 23:03:29 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int main (void)
{
	int i;
	int size;
	int tab[5];
	size = 5;

	i = 0;
	while (i <size)
	{
		tab[i] = i +1;
		i ++;	
	}
		i = 0;
		while( i < size)
	{
		printf("numero:%d\n", tab[i]);
		i++;
	} 

	ft_rev_int_tab(tab, size);
	printf("=========\n");
	i = 0;
	while( i < size)
	{
		printf("numero:%d\n", tab[i]);
		i++;
	} 
}