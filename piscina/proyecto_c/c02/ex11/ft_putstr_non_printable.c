/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:47:26 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/21 16:57:37 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned int		i;
	char				*hexadecimal;
	char				c;

	hexadecimal = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] <= 31 && str[i] > 127)
		{
			write (1, "\\", 1);
			c = hexadecimal[str[i] / 16];
			write (1, &c, 1);
			str[i] = hexadecimal[str[i] % 16];
		}
		write (1, &str[i], 1);
		i++;
	}
}
