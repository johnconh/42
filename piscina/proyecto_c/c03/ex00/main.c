/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:29:24 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/12 21:10:53 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char*s2);

int main (void)
{
	int i;
	char s1[] = "JOhn";
	char s2[] = "John";
	
	i = ft_strcmp(s1, s2);
	printf("%d", i);	
}