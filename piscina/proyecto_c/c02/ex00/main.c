/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:55:52 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/12 12:26:55 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strcpy(char *dest, char *src);

int main (void)
{
	char dest[5];
 	char src[5] = "john";
	 
	ft_strcpy(dest, src);
	printf("src: %s\ndest: %s\n", src, dest);
}