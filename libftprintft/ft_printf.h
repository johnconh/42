/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:01:40 by jdasilva          #+#    #+#             */
/*   Updated: 2022/09/26 16:34:16 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *s, ...);
int		ft_putchar(char c);
size_t	ft_strlen(char *str);
int		ft_putstr(char *str);
int		ft_putunbr(unsigned int n);
int		ft_putnbr(int n);
int		ft_puthex(size_t arg, char format);
#endif