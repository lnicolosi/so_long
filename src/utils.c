#include "../header/so_long.h"
#include <stddef.h>

int	*free_int_memory(int ***ptr)
{
	if (ptr && *ptr && **ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*x;

	x = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		x[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->heightmap)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

int	is_map_empty(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (game->map[i][j] != '\n' && game->map[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	map_border_check(t_game *game)
{
	int	i;

	i = 0;
	while (i != game->heightmap - 1)
	{
		ft_printf("heightmap : %d\n", game->heightmap);
		ft_printf("i = %d\n", i);
		ft_printf("%s\n", game->map[i]);
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[i + 1]))
		{
			ft_printf("Erreur, murs pas bien placés\n");
			//exit_point(game);
		}
		i++;
	}
}
