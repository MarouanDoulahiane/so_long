/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:39:15 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 09:41:31 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	move_up(t_data *data, int *counter)
{
	(*counter)++;
	data->map[data->y][data->x] = '0';
	data->y--;
	if (data->map[data->y][data->x] == 'C')
		data->collectibles--;
	if (data->map[data->y][data->x] == 'E'
		|| data->map[data->y][data->x] == 'B')
	{
		free_2d_array(data->map, data->rows);
		exit(0);
	}
	data->map[data->y][data->x] = 'P';
}

void	move_down(t_data *data, int *counter)
{
	(*counter)++;
	data->map[data->y][data->x] = '0';
	data->y++;
	if (data->map[data->y][data->x] == 'C')
		data->collectibles--;
	if (data->map[data->y][data->x] == 'E'
		|| data->map[data->y][data->x] == 'B')
	{
		free_2d_array(data->map, data->rows);
		exit(0);
	}
	data->map[data->y][data->x] = 'P';
}

void	move_left(t_data *data, int *counter)
{
	(*counter)++;
	data->map[data->y][data->x] = '0';
	data->x--;
	if (data->map[data->y][data->x] == 'C')
		data->collectibles--;
	if (data->map[data->y][data->x] == 'E'
		|| data->map[data->y][data->x] == 'B')
	{
		free_2d_array(data->map, data->rows);
		exit(0);
	}
	data->left = false;
	data->map[data->y][data->x] = 'P';
}

void	move_right(t_data *data, int *counter)
{
	(*counter)++;
	data->map[data->y][data->x] = '0';
	data->x++;
	if (data->map[data->y][data->x] == 'C')
		data->collectibles--;
	if (data->map[data->y][data->x] == 'E'
		|| data->map[data->y][data->x] == 'B')
	{
		free_2d_array(data->map, data->rows);
		exit(0);
	}
	data->left = true;
	data->map[data->y][data->x] = 'P';
}

int	movement(int key, t_data *data)
{
	static int	counter;

	if (key == 13 && (data->map[data->y - 1][data->x] == '0'
		|| data->map[data->y - 1][data->x] == 'C'
		|| (data->map[data->y - 1][data->x] == 'E' && !data->collectibles)
		|| data->map[data->y - 1][data->x] == 'B'))
		move_up(data, &counter);
	else if (key == 1 && (data->map[data->y + 1][data->x] == '0'
		|| data->map[data->y + 1][data->x] == 'C'
		|| (data->map[data->y + 1][data->x] == 'E' && !data->collectibles)
		|| data->map[data->y + 1][data->x] == 'B'))
		move_down(data, &counter);
	else if (key == 0 && (data->map[data->y][data->x - 1] == '0'
		|| data->map[data->y][data->x - 1] == 'C'
		|| (data->map[data->y][data->x - 1] == 'E' && !data->collectibles)
		|| data->map[data->y][data->x - 1] == 'B'))
		move_left(data, &counter);
	else if (key == 2 && (data->map[data->y][data->x + 1] == '0'
		|| data->map[data->y][data->x + 1] == 'C'
		|| (data->map[data->y][data->x + 1] == 'E' && !data->collectibles)
		|| data->map[data->y][data->x + 1] == 'B'))
		move_right(data, &counter);
	data->moves = counter;
	return (0);
}
