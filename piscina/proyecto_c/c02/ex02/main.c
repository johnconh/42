/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:37:37 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/12 17:43:34 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_alpha(char *str);

int main (void)
{
	int i;

	char str[] = "aa22aaBBB";
	i = ft_str_is_alpha(str);
	printf("Valor es:%d", i);
}