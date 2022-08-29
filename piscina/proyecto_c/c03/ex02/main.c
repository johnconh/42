/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:04:03 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/13 11:20:55 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcat(char *dest, char *src);

#include <stdio.h>

int main (void)
{
	char dest[20] = "John";
	char src[]	= "Dasilva";
	printf("%s", ft_strcat(dest, src));
}