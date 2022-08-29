/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:32:06 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/14 14:26:32 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int main (void)
{
	unsigned int nb;
	char dest[30] = "John";
	char src[]	= "Dasilva";

	nb = 352;
	printf("%s", ft_strncat(dest, src, nb));
}