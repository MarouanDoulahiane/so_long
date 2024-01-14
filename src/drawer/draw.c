/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:43:04 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 09:40:51 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	image_setup(t_data *data, int i, int j, int k)
{
	if (data->map[i][j] == 'P')
	{
		if (data->left)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->textures[0], j * 64, i * 64);
		else if (!data->left)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->textures[8], j * 64, i * 64);
	}
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->textures[1], j * 64, i * 64);
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->textures[2], j * 64, i * 64);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->textures[4 - k], j * 64, i * 64);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->textures[7], j * 64, i * 64);
	else if (data->map[i][j] == 'B')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->textures[5 + k], j * 64, i * 64);
}

void	draw(t_data *data, int i, int j)
{
	int	k;

	k = 0;
	if (data->counter >= 10000)
		data->counter = 0;
	if (data->counter >= 5000)
		k = 1;
	image_setup(data, i, j, k);
	data->counter++;
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = nb;
	while (j)
	{
		j /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

int	drawer(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			draw(data, i, j++);
			str = ft_itoa(data->moves);
			mlx_string_put(data->mlx_ptr, data->win_ptr, 32, 16, 0xFFFFFFFF,
				"moves: ");
			if (!data->moves)
				mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 16,
					0xFFFFFFFF, "0");
			else
				mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 16,
					0xFFFFFFFF, str);
			free(str);
		}
		i++;
	}
	return (0);
}
