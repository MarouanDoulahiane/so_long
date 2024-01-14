/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:42:22 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 12:17:50 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

bool	flood_fill_exit(char **map, int x, int y, t_data data)
{
	bool	reached;

	if (x <= 0 || y <= 0 || x >= data.cols || y >= data.rows
		|| map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'B')
		return (false);
	if (map[y][x] == 'E')
		return (true);
	map[y][x] = 'V';
	reached = (flood_fill_exit(map, x + 1, y, data)
			|| flood_fill_exit(map, x - 1, y, data)
			|| flood_fill_exit(map, x, y + 1, data)
			|| flood_fill_exit(map, x, y - 1, data));
	return (reached);
}

int	flood_fill_collectibles(char **map, int x, int y, t_data data)
{
	int		reached;

	reached = 0;
	if (x <= 0 || y <= 0 || x >= data.cols || y >= data.rows
		|| map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'V'
		|| map[y][x] == 'B')
		return (0);
	if (map[y][x] == 'C')
		reached++;
	map[y][x] = 'V';
	reached += flood_fill_collectibles(map, x + 1, y, data);
	reached += flood_fill_collectibles(map, x - 1, y, data);
	reached += flood_fill_collectibles(map, x, y + 1, data);
	reached += flood_fill_collectibles(map, x, y - 1, data);
	return (reached);
}

bool	valid_path_exit(t_data *data)
{
	char	**new_map;
	bool	res;

	new_map = copy_2d_array(data->map, data->rows);
	res = flood_fill_exit(new_map, data->x, data->y, *data);
	free_2d_array(new_map, data->rows);
	if (!res)
		ft_printf("%sError: no path to exit\n%s", RED, NC);
	return (res);
}

bool	valid_path_collectibles(t_data *data)
{
	char	**new_map;
	int		res;

	new_map = copy_2d_array(data->map, data->rows);
	res = flood_fill_collectibles(new_map, data->x, data->y, *data);
	free_2d_array(new_map, data->rows);
	if (res != data->collectibles)
		ft_printf("%sError: no path to collectibles\n%s", RED, NC);
	return (res == data->collectibles);
}

void	check_map_is_valid(t_data *data)
{
	_collectibles_position(data);
	check_all_items(*data, data->rows);
	if (!check_valid_wall(*data)
		|| !valid_path_exit(data)
		|| !valid_path_collectibles(data))
	{
		free_2d_array(data->map, data->rows);
		exit(1);
	}
}
