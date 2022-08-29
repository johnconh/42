/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:11:18 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/11 16:27:37 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int *ft_strupcase(char *str);

int main (void)
{
	char str[] = "abc123";
	ft_strupcase(str);
	printf("Valor es:%s", str);
}