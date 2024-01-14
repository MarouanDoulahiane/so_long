/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:56:23 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 09:36:13 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	hundler(char format, va_list arg, int *i)
{
	if (format == 'c')
		ft_putchr(va_arg(arg, int), i);
	else if (format == 's')
		ft_putstr(va_arg(arg, char *), i);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(arg, int), i);
	else if (format == 'u')
		ft_putunbr(va_arg(arg, int), i);
	else if (format == '%')
		ft_putchr('%', i);
	else if (format == 'x' || format == 'X')
		ft_puthex(va_arg(arg, unsigned int), format, i);
	else if (format == 'p')
		ft_putadd(va_arg(arg, void *), i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;

	i = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			hundler(*format, arg, &i);
		}
		else
			ft_putchr(*format, &i);
		format++;
	}
	va_end(arg);
	return (i);
}
