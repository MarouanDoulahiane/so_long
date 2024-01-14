/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:14:56 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 09:38:12 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

typedef struct data
{
	char	*remainder;
	char	buffer[BUFFER_SIZE + 1];
	char	*newline;
	char	*line;
	int		bytes_read;
}	t_get;

int	helper(t_get *data)
{
	if (!data->remainder)
		return (1);
	data->newline = ft_strchr(data->remainder, '\n');
	if (data->newline)
	{
		data->line = malloc(data->newline - data->remainder + 1 + 1);
		if (!data->line)
			return (1);
		data->line[data->newline - data->remainder + 1] = '\0';
		ft_strncpy(data->line, data->remainder, 
			data->newline - data->remainder + 1);
		data->remainder = ft_strdup(data->newline + 1, data->remainder);
		if (!data->remainder)
			return (1);
		return (0);
	}
	else if (!data->bytes_read && !data->remainder[0])
		return (2);
	else if (!data->bytes_read)
	{
		data->line = ft_strdup(data->remainder, data->remainder);
		data->remainder = NULL;
		return (0);
	}
	return (255);
}

char	*return_line(t_get *data, int fd)
{
	int	choice;

	data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	while (data->bytes_read >= 0)
	{
		data->buffer[data->bytes_read] = 0;
		data->remainder = ft_strjoin(data->remainder, data->buffer, false);
		choice = helper(data);
		if (choice == 0)
			return (data->line);
		if (choice == 1)
			return (NULL);
		else if (choice == 2)
			break ;
		data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	}
	free(data->remainder);
	data->remainder = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_get	data;

	if (!BUFFER_SIZE || fd == -1)
		return (NULL);
	if (!data.remainder)
		data.remainder = ft_strdup("", NULL);
	return (return_line(&data, fd));
}
// #include <fcntl.h>
// #include <stdio.h>

// void f(){
// 	system("leaks a.out");
// }

// int main (){
// 	int fd = open("get_next_line.c", O_RDONLY);

// 	atexit(f);
// 	char *line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }
