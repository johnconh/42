/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:48:32 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/04 19:35:39 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_comb(int na, int nb)
{
	ft_putchar ((na / 10) + 48);
	ft_putchar ((na % 10) + 48);
	ft_putchar(' ');
	ft_putchar ((nb / 10) + 48);
	ft_putchar ((nb % 10) + 48);
	if (!(na == 98 && nb == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	na;
	int	nb;

	na = 00;
	while (na <= 98)
	{
		nb = 1 + na;
		while (nb <= 99)
		{
			ft_write_comb(na, nb);
			nb++;
		}
		na++;
	}
}
