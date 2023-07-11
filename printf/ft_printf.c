/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:41 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/06/25 20:45:28 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formattype(char c, va_list ap, int *len)
{
	int	temp_len;

	temp_len = 0;
	if (c == 'c')
		temp_len = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		temp_len = ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		temp_len = ft_putnbr((long)va_arg(ap, int));
	else if (c == 'u')
		temp_len = ft_putnbr(va_arg(ap, unsigned int));
	else if (c == 'x')
		temp_len = ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		temp_len = ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		temp_len = ft_putptr((size_t)va_arg(ap, void *));
	else if (c == '%')
		temp_len = ft_putchar('%');
	if (temp_len < 0)
		return (-1);
	*len += temp_len;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	char	*str;
	va_list	ap;

	len = 0;
	str = (char *)format;
	va_start(ap, format);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) && (ft_formattype(*(++str), ap, &len) < 0))
				return (-1);
		}
		else
		{
			if (ft_putchar(*str) < 0)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(ap);
	return (len);
}
