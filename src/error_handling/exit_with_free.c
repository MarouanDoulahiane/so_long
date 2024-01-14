/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:23:07 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 12:12:05 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	_exit_with_free(t_data *data, char *msg)
{
	if (data && data->map)
		free_2d_array(data->map, data->rows);
	ft_printf("%s%s%s\n", RED, msg, NC);
	exit(1);
}

void	_exit_when_items_not_correct(t_data *data)
{
	free_2d_array(data->map, data->rows);
	ft_printf("%sError: The map must contain 1 exit", RED);
	ft_printf(", at least 1 collectible, and 1 starting ");
	ft_printf("position to be valid.\n%s", NC);
	exit(1);
}
