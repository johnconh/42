/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:34:51 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/12 17:11:29 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int main (void)
{
	int  i;
	char str[] = "a3dfdf";
	i = ft_str_is_lowercase(str);
	printf("Valor es:%d", i);
}