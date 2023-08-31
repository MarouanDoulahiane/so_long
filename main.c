// >>>>>> I must to add if there is a valid path for all chest , Good Luck dude ;)

#include "includes.h"
#include <X11/X.h>
#include <X11/keysym.h>
// #include "utils/get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strncpy(char *dest, const char *src, size_t n)
{
        size_t  i;

        i = 0;
        while (src[i] && i < n)
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
                dest[i++] = '\0';
        return (dest);
}

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*result;

	if (!(result = malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
		result[i++] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
  while (*s != '\0')
  {
    if (*s == c)
      return ((char *)s);
    s++;
  }
  if (*s == c)
    return ((char *)s);
  return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(result))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}


char    *get_next_line(int fd)
{
  static char   *remainder = NULL;
  char          buffer[BUFFER_SIZE + 1];
  int           bytes_read = 0;
  char          *newline = NULL;
  char          *line = NULL;
  void			*tmp = NULL;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return NULL;

  while ((remainder == NULL || (newline = ft_strchr(remainder, '\n')) == NULL)
        && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
  {
    buffer[bytes_read] = '\0';
    if (remainder == NULL)
	{
		tmp = remainder;
      remainder = ft_strdup(buffer);
	  	free(tmp);
	}
    else
      remainder = ft_strjoin(remainder, buffer);
  }

  if (newline)
  {
    *newline = '\0';
    line = ft_strnew(newline - remainder);
    ft_strncpy(line, remainder, newline - remainder);
	free(remainder);
    remainder = ft_strdup(newline + 1);
  }
  else if (!bytes_read && remainder)
  {
    line = ft_strdup(remainder);
	free(remainder);
    remainder = NULL;
  }

  return line;
}


int closeWindow(t_data *data)
{
	int	i = 0;
	while (data->texture[i] != NULL)
		free(data->texture[i++]);
	
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	print_move(t_data *data)
{
	data->game.nb_move++;
	printf("%d\n", data->game.nb_move);
}

int	onKeyPress(int keysym, t_data *data)
{
	int x = data->game.player_x;
	int y = data->game.player_y;
			
	if (keysym == XK_Escape)
		closeWindow(data);
	if ((keysym == XK_w || keysym == XK_W || keysym == XK_Up) && data->texture[y - 1][x] != '1')
	{
		if (data->texture[y - 1][x] == 'E' && data->game.had_chest == data->game.nb_chest)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.exit1, x * 64, (y - 1) * 64);
			data->game.player_y--;
		}
		else if (data->game.is_right && data->texture[y - 1][x] != 'E')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.player01, x * 64, (y - 1) * 64);
			data->game.player_y--;
		}
		else if (data->texture[y - 1][x] != 'E')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.player00, x * 64, (y - 1) * 64);
			data->game.player_y--;
		}
	}
	else if ((keysym == XK_s || keysym == XK_S || keysym == XK_Down) && data->texture[y + 1][x] != '1')
	{
		if (data->texture[y + 1][x] == 'E' && data->game.had_chest == data->game.nb_chest)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.exit1, x * 64, (y + 1) * 64);
			data->game.player_y++;	
		}
		else if (data->game.is_right && data->texture[y + 1][x] != 'E')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.player01, x * 64, (y + 1) * 64);
			data->game.player_y++;	
		}
		else if (data->texture[y + 1][x]  != 'E')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.player00, x * 64, (y + 1) * 64);
			data->game.player_y++;	
		}
	}
	else if ((keysym == XK_d || keysym == XK_D || keysym == XK_Right) && data->texture[y][x + 1] != '1')
	{
		if (data->texture[y][x + 1] == 'E' && data->game.had_chest == data->game.nb_chest)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.exit1, (x + 1) * 64, y  * 64);
			data->game.player_x++;	
		}
		else if (data->texture[y][x + 1] != 'E')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.player00, (x + 1) * 64, y * 64);
			data->game.is_right = 0;
			data->game.player_x++;	
		}		
	}
	else if ((keysym == XK_a || keysym == XK_A || keysym == XK_Left) && data->texture[y][x - 1] != '1')
	{
		if (data->texture[y][x - 1] == 'E' && data->game.had_chest == data->game.nb_chest)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.exit1, (x - 1) * 64, y  * 64);
			data->game.player_x--;	
		}
		else if (data->texture[y][x - 1] != 'E')
		{

			mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->game.player01, (x - 1) * 64, y * 64);
			data->game.is_right = 1;
			data->game.player_x--;	
		}

	}
	if (data->game.player_x != x || data->game.player_y != y)
		print_move(data);
	if (data->texture[data->game.player_y][data->game.player_x] == 'C')
	{
		data->game.had_chest++;
		data->texture[data->game.player_y][data->game.player_x] = '0';
	}
	if (data->texture[y][x] == 'P' && data->texture[data->game.player_y][data->game.player_x] != 'E' )
	{
		data->texture[y][x] = '0';
		data->texture[data->game.player_y][data->game.player_x] = 'P';
	}
	return (0);
}

int	whenWeExit(int keysym, t_data *data)
{
	if (data->texture[data->game.player_y][data->game.player_x] == 'E' && data->game.had_chest == data->game.nb_chest)
	{
		sleep(2);
		closeWindow(data);
	}
	return (0);
}

int draw(t_data *data)
{
	int x = 0;
	int y = 0;
	while (data->texture[y])
	{
		x = 0;
		while (data->texture[y][x])
		{
			if (data->texture[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->game.wall, x * 64, y * 64);
			else if (data->texture[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->game.empty, x * 64, y * 64);
			else if (data->texture[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->game.exit0, x * 64, y * 64);
			else if (data->texture[y][x] == 'P')
			{
				if (!data->game.is_right)
					mlx_put_image_to_window(data->mlx, data->win, data->game.player00, x * 64, y * 64);
				else
					mlx_put_image_to_window(data->mlx, data->win, data->game.player01, x * 64, y * 64);
				data->game.player_x = x;
				data->game.player_y = y;
			}
			else if (data->texture[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->game.chest, x * 64, y * 64);
				if (data->game.chest_count)
					data->game.nb_chest++;
			}
			x++;
		}
		y++;
	}
	if (data->game.chest_count)
		data->game.chest_count = 0;
}

int	isValid(int	row, int col, int rows, int cols, char **texture)
{
	return (texture[row][col] != '1' && row > 0 && row < rows && col >= 0 && col < cols);
}

int	findPath(Point start, Point end, int rows, int cols, char **texture)
{
	Point	queue[rows * cols];
	int		visited[rows][cols];
	int i;
	int j;

	i = 0;
	while (i < rows)
	{
		j = 0;
        while (j < cols) {
            visited[i][j] = 0;
			j++;
        }
		i++;
    }
	//     for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         visited[i][j] = 0;
    //     }
    // }

	// Pointers for our queue
	int front = 0, rear = 0;
	queue[rear++] = start;
	visited[start.row][start.col] = 1;

	// here i will keep goint until we make queue empty
	while (front < rear)
	{
		Point	current = queue[front++];
		if (current.row == end.row && current.col == end.col)
			return (1);
		int dr[] = {-1, 1, 0, 0};
		int	dc[] = {0, 0, -1, 1};
		i = 0;
		while (i < 4)
		{
			int newRow = current.row + dr[i];
			int newCol = current.col + dc[i];
			if (isValid(newRow, newCol, rows, cols, texture) && !visited[newRow][newCol])
			{
				Point	neightber = {newRow, newCol};
				queue[rear++] = neightber;
				visited[newRow][newCol] = 1;
			}
			i++;
		}
	}
	return (0);	
}


int	main(int argc, char **argv)
{
	int size;

	t_data data;

	
	
	char *texture[50] = {NULL};
	int map = open("map.ber", O_RDONLY);
	if (map == -1)
	{
		perror("Error msg:");
		return (1);
	}
	int rows = 0;
	int cols;
	data.game.nb_start = 0;
	data.game.nb_exit = 0;
	Point start;
	Point end ;

	while ((texture[rows] = get_next_line(map)) != NULL)
	{
		cols = 0;
		while (texture[rows][cols] != '\0')
		{
			if (texture[rows][cols] == 'P')
			{
				data.game.nb_start++;
				start.col = cols;
				start.row = rows;
			}
			else if (texture[rows][cols] == 'E')
			{
				data.game.nb_exit++;
				end.col = cols;
				end.row = rows;

			}
			cols++;
		}
		rows++;
	}
	


	// check if we have more than one "exit/start"
	if (data.game.nb_start > 1)
		write(2, "Error msg: Find more than one \"start\"\n", 38);
	if (data.game.nb_exit > 1)
		write(2, "Error msg: Find more than one \"exit\"\n", 37);
	// Check if we have a full wall or we return error
	int x = 0;
	int y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (texture[y][x] != '1' && (y == 0 || y == rows - 1 || x == 0 || x == cols - 1))
			{
				write(2, "Error : you have a not valid map check again!\n", 46);
				return (1);
			}
			x++;
		}
		y++;		
	}

	// Bearth first search algo to check if we have a valid path or not
	if (!findPath(start, end, rows, cols, texture))
	{
		write(2, "Error msg: Your map have a not valid path\n", 42);
		return (1);
	}
// =================
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		write(2, "Error: mlx_init failed\n", 23);
		return (1);
	}

	data.win = mlx_new_window(data.mlx, cols * 64, rows * 64, "So_Long");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		write(2, "Error: mlx_new_window failed\n", 29);
		return (1);
	}


// =================

	data.game.player00 = mlx_xpm_file_to_image(data.mlx, PLAYER00, &size, &size);
	data.game.player01 = mlx_xpm_file_to_image(data.mlx, PLAYER01, &size, &size);
	data.game.chest = mlx_xpm_file_to_image(data.mlx, CHEST0, &size, &size);
	data.game.wall = mlx_xpm_file_to_image(data.mlx, WALL, &size, &size);
	data.game.empty = mlx_xpm_file_to_image(data.mlx, EMPTY, &size, &size);
	data.game.exit0 = mlx_xpm_file_to_image(data.mlx, EXIT0, &size, &size);
	data.game.exit1 = mlx_xpm_file_to_image(data.mlx, EXIT1, &size, &size);
	data.game.had_chest = 0;
	data.game.nb_chest = 0;
	data.game.chest_count = 1;
	data.game.is_right = 0;
	data.texture = texture;
	data.game.nb_move = 0;







// =================

	// key Events && Here wetttttttttttt using a lambda function
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, whenWeExit, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, onKeyPress, &data);
	// Minimize
	mlx_expose_hook(data.win, draw, &data);
	
	// Destroy Window X button
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, closeWindow, &data);
	// Loop over the MLX pointer 
	mlx_loop(data.mlx);


	// Free all allocated Memory
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}