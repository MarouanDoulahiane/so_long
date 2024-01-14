/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:44:43 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 12:18:13 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define NC			"\033[0m"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[9];
	int		x;
	int		y;
	bool	left;
	int		collectibles;
	int		cols;
	int		rows;
	int		counter;
	int		moves;
	char	**map;
}	t_data;

// Get Next Line
char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1, char *old_remainder);
char	*ft_strjoin(char *s1, char const *s2, bool to_free);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(const char *s);

// FT Printf
int		ft_printf(const char *format, ...);

void	ft_putchr(char c, int *i);
void	ft_putstr(char *s, int *i);
void	ft_putnbr(int n, int *i);
void	ft_putunbr(unsigned int n, int *i);
void	ft_puthex(unsigned int n, char xX, int *i);
void	ft_putadd(void *ptr, int *i);

// Error Handling
void	_invalid_args(int ac);
void	_invalid_map(void);
void	_malloc_error(void);
void	_exit_with_free(t_data *data, char *msg);
void	_exit_when_items_not_correct(t_data *data);

// Map checker
void	_collectibles_position(t_data *data);
void	check_all_items(t_data data, int rows);
bool	check_valid_wall(t_data data);

void	check_map_is_valid(t_data *data);
void	setup_map(t_data *data, char *file);

// Movement
int		movement(int key, t_data *data);

// Draw
int		drawer(t_data *data);

// Tools
size_t	count_len(const char *s);
size_t	count_2d(char **s);
char	**ft_split(char const *s, char c);
char	**copy_2d_array(char **array, int size);
void	free_2d_array(char **array, int size);

#endif