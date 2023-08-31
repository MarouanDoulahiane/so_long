#ifndef INCLUDES_H
#define INCLUDES_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <X11/keysym.h>
// #include "utils/get_next_line.h"

# define WIDTH 800
# define HIEGHT 360
# define SIZE 120
# define BUFFER_SIZE 1

# define PLAYER00 "textures/char/player00.xpm"
# define PLAYER01 "textures/char/player01.xpm"
// # define PLAYER1 "textures/char/char1.xpm"
// # define PLAYER2 "textures/char/char2.xpm"
// # define PLAYER3 "textures/char/char3.xpm"
// # define PLAYER4 "textures/char/char4.xpm"
// # define PLAYER5 "textures/char/char5.xpm"
// # define PLAYER6 "textures/char/char6.xpm"

# define CHEST0 "textures/chest/chest0.xpm"
// # define CHEST1 "textures/chest/chest1.xpm"

# define WALL "textures/env/wall.xpm"
# define EMPTY "textures/env/empty.xpm"

# define EXIT0 "textures/exit/exit0.xpm"
# define EXIT1 "textures/exit/exit1.xpm"


typedef struct s_game
{
	void	*player00;
	void	*player01;
	void	*chest;
	void	*wall;
	void	*empty;
	void	*exit0;
	void	*exit1;

	int		player_x;
	int		player_y;
	int		chest_count;
	int		nb_chest;
	int		had_chest;
	int		is_right;
	int		nb_move;
	int		nb_exit;
	int		nb_start;
}			t_game;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	char	**texture;
	t_game	game;
}			t_data;

typedef struct
{
	int	row;
	int	col;
}		Point;


#endif