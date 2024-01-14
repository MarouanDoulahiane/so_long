/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:10:11 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 12:20:24 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header.h"

int	destroy(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		free_2d_array(data->map, data->rows);
		exit(0);
	}
	return (0);
}

int	destroy_x(t_data *data)
{
	free_2d_array(data->map, data->rows);
	exit(0);
}

void	mlx_xpm_checker(t_data data)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		if (!data.textures[i])
			_exit_with_free(&data, "Error: mlx_xpm_file_to_image failed\n");
		i++;
	}
}

void	xmp_to_images(t_data *data, int *size)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		_exit_with_free(data, "Error: mlx_init failed\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->cols * 64,
			data->rows * 64, "so_long");
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player00.xpm", size, size);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/empty.xpm", size, size);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", size, size);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/chest00.xpm", size, size);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/chest01.xpm", size, size);
	data->textures[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/bonus00.xpm", size, size);
	data->textures[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/bonus01.xpm", size, size);
	data->textures[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", size, size);
	data->textures[8] = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player01.xpm", size, size);
	mlx_xpm_checker(*data);
}

int	main(int ac, char **av)
{
	int		size;
	t_data	data;

	_invalid_args(ac);
	setup_map(&data, av[1]);
	check_map_is_valid(&data);
	xmp_to_images(&data, &size);
	mlx_loop_hook(data.mlx_ptr, &drawer, &data);
	mlx_hook(data.win_ptr, 2, 0, &movement, &data);
	mlx_hook(data.win_ptr, 17, 0, &destroy_x, &data);
	mlx_key_hook(data.win_ptr, &destroy, &data);
	return (mlx_loop(data.mlx_ptr), 0);
}
