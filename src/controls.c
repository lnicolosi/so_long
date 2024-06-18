#include "../header/so_long.h"

static int	process_move(t_game *game, int newX, int newY)
{
	char	cell;

	cell = game->map[newY][newX];
	if (cell == 'E' && game->collectables != 0)
		return (0);
	if (cell == 'E' && game->collectables == 0)
	{
		ft_printf("Bravo tu as gagné !\n");
		exit_point(game);
	}
	if (cell == '0' || cell == 'C')
	{
		if (cell == 'C')
			game->collectables--;
		game->map[newY][newX] = 'P';
		game->map[game->y_axis][game->x_axis] = '0';
		game->x_axis = newX;
		game->y_axis = newY;
		game->counter++;
	}
	return (1);
}

static int	move_player(t_game *game, int command)
{
	int	newX;
	int newY;

	newX = game->x_axis;
	newY = game->y_axis;
	if (command == 13 || command == 126)
		newY--;
	else if (command == 1 || command == 125)
		newY++;
	else if (command == 0 || command == 123)
		newX--;
	else if (command == 2 || command == 124)
		newX++;
	if (newX < 0 || newY < 0 || newX >= game->widthmap \
		|| newY >= game->heightmap || game->map[newY][newX] == '1')
		return (0);
	return (process_move(game, newX, newY));
}

int	controls_working(int command, t_game *game)
{
	int works;

	works = 0;
	if (command == 53)
		exit_point(game);
	else
		works = move_player(game, command);
	if (works)
	{
		adding_in_graphics(game);
		ft_printf("Mouvement : %d\n", game->counter);
		ft_printf("Fleurs restantes : %d\n", game->collectables);
	}
	return (1);
}
