/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:56:13 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 09:35:39 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	ft_putunbr(unsigned int n, int *i)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, i);
		ft_putnbr(n % 10, i);
	}
	else
		ft_putchr(n + 48, i);
}

void	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", i);
	else
	{
		if (n < 0)
		{
			ft_putchr('-', i);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10, i);
			ft_putnbr(n % 10, i);
		}
		else
			ft_putchr(n + 48, i);
	}
}

void	ft_puthex(unsigned int n, char xX, int *i)
{
	char	*base;

	if (xX == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchr(base[n], i);
	else
	{
		ft_puthex(n / 16, xX, i);
		ft_puthex(n % 16, xX, i);
	}
}
