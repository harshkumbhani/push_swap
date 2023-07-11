/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:48 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/02 17:22:07 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Prints number on the terminal, similat to ITOA()
/// @param n The number to be printed
int	ft_putnbr(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		if (len < 0)
			return (-1);
		n = -n;
	}
	else if (n == 0)
		return (ft_putchar('0'));
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		if (len < 0)
			return (-1);
	}
	len += ft_putchar((n % 10) + 48);
	return (len);
}

int	ft_puthex(size_t n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16, base);
		if (len < 0)
			return (-1);
	}
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(size_t n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	len += ft_putstr("0x");
	if (len < 0)
		return (-1);
	len += ft_puthex(n, base);
	return (len);
}
