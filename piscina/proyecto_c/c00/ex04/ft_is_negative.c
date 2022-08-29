/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:29:29 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/04 19:33:52 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char a)
{
	write (1, &a, 1);
}

void	ft_is_negative(int n)
{
	if (n <= -1)
	{
		ft_putchar('N');
	}
	else if (n >= 1 || n == 0)
	{
		ft_putchar('P');
	}
}
