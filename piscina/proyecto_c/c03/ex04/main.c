/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:57:24 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/13 13:57:39 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strstr(char *str, char *to_find);

int main (void)
{
	char str[13] = "hola ja john";
	char to_find[3] = "jo";
	int i;
	char *p;
	
	i = 0;
	
	p = ft_strstr(str, to_find);
	while (p[i])
	{
		printf ("%c", p[i]);
		i++; 
	}
}