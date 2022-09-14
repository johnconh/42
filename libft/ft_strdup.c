/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:27:33 by jdasilva          #+#    #+#             */
/*   Updated: 2022/09/14 13:37:37 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, size + 1);
	*(dst + size) = '\0';
	return (dst);
}
