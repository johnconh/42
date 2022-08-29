/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:34:51 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:16 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int *ft_strlowcase(char *str);

int main (void)
{
	char str[] = "ABC123";
	ft_strlowcase(str);
	printf("Valor es:%s", str);
}