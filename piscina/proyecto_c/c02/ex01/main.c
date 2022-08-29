/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:39:05 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/12 12:52:02 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main (void)
{
	unsigned int n;
	char dest[5];
 	char src[5] = "john";
	 
	n =3;
	ft_strncpy(dest, src, n);
	printf("src: %s\ndest: %s\n", src, dest);
}