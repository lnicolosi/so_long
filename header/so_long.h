#ifndef	SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define PIX 64

typedef struct s_game
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		nbrcollectable;
	int		nbrplayer;
	int		nbrexit;
	int		exit_open;
	int		player_found;
	int		player_x;
	int		player_y;
	int		exit_found;
	int		exit_x;
	int		exit_y;
	int		collectabled;
	int		y_axis;
	int		x_axis;
	int		collectables;
	int		counter;

	char	**map;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*sol;
	void	*mur;
	void	*joueur;
	void	*porte;
	void	*fleur;

}	t_game;

int		exit_point(t_game *game);
int		*free_int_memory(int ***ptr);
void	*ft_memset(void *s, int c, size_t n);
void	free_map(t_game *game);
int		is_map_empty(t_game *game);
void	map_border_check(t_game *game);
int		reading_map(t_game *game, char **argv);
void	ft_print_error(t_game *game);
void	check_errors(t_game *game);
void	explore_find_player(t_game *game);
void	explore_complete(t_game *game, int **visited);
void	explore_map(t_game *game, int x, int y, int **visited);
void	free_visited(int **visited, int height);
void	verify_feasibility(t_game *game);
void	place_images_in_game(t_game *game);
void	adding_in_graphics(t_game *game);
int		controls_working(int command, t_game *game);

#endif
