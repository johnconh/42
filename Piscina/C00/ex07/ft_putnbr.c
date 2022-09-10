/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:40:44 by jdasilva          #+#    #+#             */
/*   Updated: 2022/09/06 19:40:55 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char n)
{
	write (1, &n, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb == -2147483648)
	{
		write (1, "2147483648", 10);
	}
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(nb % 10 + 48);
	}
}


void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	n = n * 10 - '0';
	write(1, &n, 1);
}

