#include "../header/so_long.h"

static int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->widthmap)
	{
		if (game->map[0][j] != '1' || game->map[game->heightmap - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < game->heightmap)
	{
		if (game->map[i][0] != '1' || game->map[i][game->widthmap - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	check_cell_validity(t_game *game, int height, int width)
{
	char	cell;

	cell = game->map[height][width];
	if (cell != '1' && cell != '0' && cell != 'P' \
			&& cell != 'E' && cell != 'C' && cell != '\n')
	{
		ft_printf("Erreur caractère : '%c'\n", cell);
		exit_point(game);
	}
	if (cell == 'C')
		game->nbrcollectable++;
	if (cell == 'P')
		game->nbrplayer++;
	if (cell == 'E')
		game->nbrexit++;
}

static void	validate_cell(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap -1)
	{
		width = 0;
		while (width < game->widthmap)
		{
			check_cell_validity(game, height, width);
			width++;
		}
		height++;
	}
	ft_print_error(game);
}

void	ft_print_error(t_game *game)
{
	if (game->nbrplayer != 1)
	{
		ft_printf("Erreur : %d Joueur(s) trouvé(s)\n", game->nbrplayer);
		exit_point(game);
	}
	if (game->nbrcollectable < 1)
	{
		ft_printf("Erreur : %d Collectible trouvé\n", game->nbrcollectable);
		exit_point(game);
	}
	if (game->nbrexit != 1)
	{
		ft_printf("Erreur : %d Sortie(s) trouvée(s)\n", game->nbrexit);
		exit_point(game);
	}
	if (game->heightmap == game->widthmap)
	{
		ft_printf("Erreur : la Map n'est pas rectangulaire\n");
		exit_point(game);
	}
}

void	check_errors(t_game *game)
{
	if (is_map_empty(game))
	{
		ft_printf("Erreur : la carte est vide\n");
		exit_point(game);
	}
	if (!check_walls(game))
	{
		ft_printf("Erreur : placement des murs incorrects\n");
		exit_point(game);
	}
	map_border_check(game);
	validate_cell(game);
	verify_feasibility(game);
}
