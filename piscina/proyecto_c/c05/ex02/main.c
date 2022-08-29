/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:19:11 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/18 19:45:51 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_power(int nb, int power);

int main (void)
{
	int nb;
	int power;

	nb = 2;
	power = 3;
	printf("%d", ft_iterative_power(nb, power));
}