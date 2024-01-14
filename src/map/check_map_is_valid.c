/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:29:36 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 12:18:46 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	check_all_items(t_data data, int rows)
{
	static int	_exit;
	static int	_player;
	static int	_collectible;
	static int	j;

	while (rows--)
	{
		j = -1;
		while (++j < data.cols)
		{
			if (data.map[rows][j] == 'P')
				_player++;
			else if (data.map[rows][j] == 'C')
				_collectible++;
			else if (data.map[rows][j] == 'E')
				_exit++;
			else if (data.map[rows][j] != '0'
				&& data.map[rows][j] != '1'
				&& data.map[rows][j] != 'B')
				_exit_with_free(&data,
					"Error: map must contain only 0, 1, P, C, E, (bonus)B.\n");
		}
	}
	if (!(_collectible >= 1 && _exit == 1 && _player == 1))
		_exit_when_items_not_correct(&data);
}

bool	check_valid_wall(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.rows)
	{
		j = 0;
		while (j < data.cols)
		{
			if ((i == 0 || i == data.rows - 1) && data.map[i][j] != '1')
				return (ft_printf("%sError: The map must be closed by walls\n%s",
						RED, NC), 0);
			if ((j == 0 || j == data.cols - 1) && data.map[i][j] != '1')
				return (ft_printf("%sError: The map must be closed by walls\n%s",
						RED, NC), 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	_collectibles_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == 'C')
				data->collectibles++;
			if (data->map[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
			}
			j++;
		}
		i++;
	}
}
