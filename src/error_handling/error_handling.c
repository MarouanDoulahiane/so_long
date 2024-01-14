/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:17:23 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/23 19:46:51 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	_invalid_args(int ac)
{
	if (ac != 2)
	{
		ft_printf("%sError: `usage` ./so_long <path/to_your/map.ber>\n%s",
			YELLOW, NC);
		exit(1);
	}
}

void	_invalid_map(void)
{
	ft_printf("%sError: `invalid map` ./so_long <path/to_your/map.ber>\n%s",
		RED, NC);
	exit(1);
}

void	_malloc_error(void)
{
	ft_printf("%sError: `malloc error`\n%s", RED, NC);
	exit(1);
}
