/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabe <jabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:28:09 by jabe              #+#    #+#             */
/*   Updated: 2025/06/26 17:02:23 by jabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (*format == 'x' || *format == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), *format));
	if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ag;

	len = 0;
	if (format == NULL)
		return (-1);
	va_start(ag, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			len += format_check(format, ag);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(ag);
	return (len);
}
