/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:03:28 by jdasilva          #+#    #+#             */
/*   Updated: 2022/09/14 17:14:55 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	if (!s)
		return (0);
	dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dst)
		return (0);
	i = -1;
	while (s[++i])
		dst[i] = f(i, ((char *)s)[i]);
	dst[i] = '\0';
	return (dst);
}
