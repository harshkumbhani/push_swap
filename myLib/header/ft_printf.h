/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:45 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/02 14:42:21 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_formattype(char c, va_list ap, int *i);
int	ft_putchar(char c);
int	ft_strlen(char *s);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_putptr(size_t n);
int	ft_puthex(size_t n, char *base);

#endif
