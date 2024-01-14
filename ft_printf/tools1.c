/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:21:53 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 09:35:51 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	ft_putchr(char c, int *i)
{
	int	state;

	state = write(1, &c, 1);
	if (state == -1)
	{
		*i = -1;
		return ;
	}
	(*i)++;
}

void	ft_putstr(char *s, int *i)
{
	if (s == NULL)
		ft_putstr("(null)", i);
	while (s && *s)
	{
		ft_putchr(*s, i);
		s++;
	}
}

void	ft_putaddhex(unsigned long int n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchr(base[n], i);
	else
	{
		ft_putaddhex(n / 16, i);
		ft_putaddhex(n % 16, i);
	}
}

void	ft_putadd(void *ptr, int *i)
{
	unsigned long int	add;

	ft_putstr("0x", i);
	if (!ptr)
		ft_putchr('0', i);
	else
	{
		add = (unsigned long int)ptr;
		ft_putaddhex(add, i);
	}
}
