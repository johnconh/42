/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:59:40 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/06 21:13:48 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_strlen(char *str);

int main (void)
{
	char str[] = "john";
	printf ("nombre:%s\ncaracteres:%d\n", str, ft_strlen(str));
}