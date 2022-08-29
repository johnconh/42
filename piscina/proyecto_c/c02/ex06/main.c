/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:54:32 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/12 17:54:46 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_printable(char *str);

int main (void)
{
	int i;
	char str[] = "A()_:\nc";
	i = ft_str_is_printable(str);
	printf("Valor es:%d", i);
}