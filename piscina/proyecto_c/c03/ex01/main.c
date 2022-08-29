/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:56:43 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/13 10:30:48 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_strncmp (char *s1, char *s2, unsigned int n);

int main (void)
{
	unsigned int n;
	int i;
	
	char s1[] = "john";
 	char s2[] = "johnnn";
	 
	n =3;
	i = ft_strncmp (s1, s2, n);
	printf("%d", i);
}