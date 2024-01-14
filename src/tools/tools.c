/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:40:00 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 12:18:29 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	free_2d_array(char **array, int size)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i < size)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

char	**copy_2d_array(char **array, int size)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		_malloc_error();
	i = 0;
	while (i < size)
	{
		map[i] = ft_strdup(array[i], NULL);
		if (!map[i])
		{
			free_2d_array(map, i);
			free_2d_array(array, size);
			_malloc_error();
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

size_t	count_len(const char *s)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s && s[i])
	{
		i++;
		if (s[i] != '\n')
			counter++;
	}
	return (counter);
}

size_t	count_2d(char **s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
