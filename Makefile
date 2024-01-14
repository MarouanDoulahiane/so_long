CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	  ft_printf/ft_printf.c ft_printf/tools1.c ft_printf/tools2.c \
	  src/drawer/draw.c src/error_handling/error_handling.c src/error_handling/exit_with_free.c \
	  src/map/check_map_is_valid.c src/map/map_checker.c src/map/setup.c \
	  src/moves/movement.c src/tools/ft_split.c src/tools/tools.c

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): inc/header.h $(SRC)
	@$(CC) $(CFLAGS) -o $(NAME) $(MLX_FLAGS) $(SRC)

clean:
	@$(RM) $(NAME)

fclean: clean
	@$(RM) $(NAME)
re: fclean all

.PHONY: clean
