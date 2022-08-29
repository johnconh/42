/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:24:04 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/14 16:29:23 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				d;
	unsigned int	c;

	d = 0;
	while (dest[d])
	{
		d++;
	}
	c = 0;
	while (src[c] && c < nb)
	{
		dest[d] = src[c];
		c++;
		d++;
	}
	dest[d] = '\0';
	return (dest);
}
