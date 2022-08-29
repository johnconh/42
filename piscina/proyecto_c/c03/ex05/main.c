/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:28:51 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/13 16:59:42 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main (void)
{
	unsigned int size;
	char dest[20] = "John";
	char src[20] = "Dasilva";

	size = 20;
	printf("%u", ft_strlcat(dest, src, size));
}