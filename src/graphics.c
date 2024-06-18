#include "../header/so_long.h"

void	place_p_c(t_game *game, int height, int width, char cell)
{
	if (cell == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
						  game->joueur, width * PIX, height * PIX);
		game->y_axis = height;
		game->x_axis = width;
	}
	if (cell == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
						  game->fleur, width * PIX, height * PIX);
		game->collectables++;
	}
}

void	*load_image(t_game *game, char *path)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (!img)
	{
		ft_printf("Erreur chargement image : %s\n", path);
		exit_point(game);
	}
	return (img);
}

void	place_images_in_game(t_game *game)
{
	game->sol = load_image(game, "Assets/Sol.xpm");
	game->mur = load_image(game, "Assets/Mur.xpm");
	game->joueur = load_image(game, "Assets/Perso.xpm");
	game->porte = load_image(game, "Assets/Door.xpm");
	game->fleur = load_image(game, "Assets/Fleur.xpm");
}

void	cell_orga(char cell, int height, int width, t_game *game)
{
	cell = game->map[height][width];
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sol, \
						 width * PIX, height * PIX);
	if (cell == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->mur, \
						  width * PIX, height * PIX);
	else if (cell == 'C')
		place_p_c(game, height, width, cell);
	else if (cell == 'P')
		place_p_c(game, height, width, cell);
	else if (cell == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->porte, \
						  width * PIX, height * PIX);
}

void	adding_in_graphics(t_game *game)
{
	int		height;
	int		width;
	char	cell;

	height = 0;
	game->collectables = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (width < game->widthmap)
		{
			cell = game->map[height][width];
			cell_orga(cell, height, width, game);
			width++;
		}
		height++;
	}
}
