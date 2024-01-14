/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:09:14 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 12:08:36 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*reader(int fd)
{
	char	*line;
	char	*collecter;
	int		i;
	size_t	len;

	i = 0;
	collecter = NULL;
	line = get_next_line(fd);
	while (line)
	{
		len = count_len(line);
		if (!i)
			collecter = ft_strdup(line, line);
		else
			collecter = ft_strjoin(collecter, line, true);
		line = get_next_line(fd);
		if (line && count_len(line) != len)
		{
			free(collecter);
			free(line);
			_invalid_map();
		}
		i++;
	}
	return (collecter);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!to_find[j])
		return (str);
	while (str[i])
	{
		while (str[i + j] == to_find[j])
		{
			if (!to_find[j + 1])
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

void	check_file(char *name)
{
	int		i;
	char	*ext;

	i = 0;
	ext = ft_strstr(name, ".ber");
	if (!ext || ext[4] != '\0')
		_exit_with_free(NULL, "Error: Bad file extension (.ber)\n");
}

void	setup_map(t_data *data, char *name)
{
	char	*collecter;
	int		fd;

	check_file(name);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		_invalid_map();
	if (read(fd, NULL, 0) == -1)
		_invalid_map();
	collecter = reader(fd);
	close(fd);
	if (!collecter)
		_exit_with_free(NULL, "Error: Empty map\n");
	data->map = ft_split(collecter, '\n');
	if (!data->map)
		_malloc_error();
	data->rows = count_2d(data->map);
	if (data->rows)
		data->cols = ft_strlen(data->map[0]);
	if (data->rows == data->cols)
		_exit_with_free(data, "Error:  The map must be rectangular.");
	data->counter = 0;
	data->left = true;
}
