/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:43:25 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/06 21:45:22 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_ft(int *nbr);

int main (void)
{
	int nbr;

	nbr = 10;
	ft_ft(&nbr);
	printf ("el valor de nbr es:%d\n", nbr);	
}