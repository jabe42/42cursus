/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabe <jabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:12:49 by jabe              #+#    #+#             */
/*   Updated: 2025/06/26 17:01:58 by jabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = ft_count_digits_unsigned(n);
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (len);
}

static int	ft_count_hex_digits(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_putnbr_hex(unsigned int n, char format)
{
	char	*hex;
	int		len;

	len = ft_count_hex_digits(n);
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, format);
		ft_putnbr_hex(n % 16, format);
	}
	else
		ft_putchar(hex[n]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	char				*hex;
	char				buf[20];
	int					i;
	int					len;
	uintptr_t			addr;

	hex = "0123456789abcdef";
	i = 0;
	len = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	addr = (uintptr_t)ptr;
	len += write(1, "0x", 2);
	while (addr > 0)
	{
		buf[i++] = hex[addr % 16];
		addr /= 16;
	}
	while (i-- > 0)
		len += ft_putchar(buf[i]);
	return (len);
}
