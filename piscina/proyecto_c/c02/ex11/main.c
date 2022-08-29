/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:22:51 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/12 12:55:39 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_non_printable(char *str);

int main (void)
{
	char str[]="Coucou\ntu vas bien ?";
	
	ft_putstr_non_printable(str);
}