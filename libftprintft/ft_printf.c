/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:05:18 by jdasilva          #+#    #+#             */
/*   Updated: 2022/09/26 16:47:19 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write(va_list arg, char format, int len)
{
	if (format == 'c')
		len += ft_putchar(va_arg (arg, int));
	else if (format == 's')
		len += ft_putstr(va_arg (arg, char *));
	else if (format == 'p')
		len += ft_putstr("0x") + ft_puthex (va_arg (arg, size_t), format);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg (arg, int));
	else if (format == 'u')
		len += ft_putunbr(va_arg (arg, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg (arg, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			len = ft_write(arg, *++format, len);
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end (arg);
	return (len);
}
