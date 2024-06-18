#include "../header/so_long.h"

static int	width_of_map(char *str)
{
	int	width;

	width = 0;
	while (str[width])
		width++;
	if (str[width - 1] == '\n')
		return (width - 1);
	else
		return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temp;
	int		i;

	i = 0;
	if (!line)
		return (0);
	game->heightmap++;
	temp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temp)
		return (0);
	temp[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

static int	argv_check(char *str)
{
	int		i;
	int		j;
	char	*str2;

	str2 = ".ber";
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == str2[j])
		{
			i++;
			j++;
		}
		i++;
	}
	ft_printf("j = %d\n", j);
	if (j == 5)
		return (1);
	else
		return (0);
}

int free_close_return(t_game *game)
{
	free_map(game);
	close(game->fd);
	return (0);
}

int	reading_map(t_game *game, char **argv)
{
	char	*readmap;
	ft_printf("debut fonction\n");
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0 || argv_check(argv[1]) == 0)
	{
		ft_printf("fd = %d\n", game->fd);
		ft_printf("Error, can't open map : '%s'\n", argv[1]);
		return (0);
	}
	readmap = get_next_line(game->fd);
	while (readmap != NULL)
	{
		if (!add_line(game, readmap))
			free_close_return(game);
		readmap = get_next_line(game->fd);
	}
	close(game->fd);
	if (game->map == NULL || game->heightmap == 0 || game->map[0] == NULL)
	{
		ft_printf("Erreur : carte vide...\n");
		return (0);
	}
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
