/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:52 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/27 15:40:57 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		s = "(null)";
	if (write(1, s, ft_strlen(s)) < 0)
		return (-1);
	len += ft_strlen(s);
	return (len);
}
