/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:06:34 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/14 14:46:03 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	c;
	unsigned int	d;

	d = 0;
	while (dest[d])
	{
		d++;
	}

	c = 0;
	while (src[c])
	{
		dest[d] = src[c];
		c++;
		d++;
	}
	d = size;
	return (*dest);
}
