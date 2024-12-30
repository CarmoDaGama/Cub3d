#include "../../includes/cube_bonus.h"

bool	is_map_valid(t_gm *game)
{
	char	**m_copy;

	if (game->map->matriz[0] == NULL)
		return (ft_err_msg("Empty Map!", false));
	m_copy = ft_matrizdup(game->map->matriz);
	if (!have_onlyvalid_ch(game) || !are_all_lines_valid(game)
		|| !is_player_valid(game) || !is_map_closed(m_copy))
		return (ft_free_matriz(m_copy), false);
	game->map->h = ft_matrizlen(game->map->matriz);
	game->map->w = ft_matriz_big_line(game->map->matriz);
	ft_free_matriz(m_copy);
	return (true);
}

bool	is_player_valid(t_gm *game)
{
	int		i;
	int		j;
	int		qt;

	i = -1;
	j = 0;
	qt = 0;
	while (game->map->matriz[++ i])
	{
		j = -1;
		while (game->map->matriz[i][++ j])
		{
			if (ft_strchr("NSEW", game->map->matriz[i][j]))
			{
				qt ++;
				game->map->plyr_x = j;
				game->map->plyr_y = i;
				game->map->plyr_dir = game->map->matriz[i][j];
			}
		}
	}
	if (qt != 1)
		return (ft_err_msg("Invalid player on map", false));
	return (true);
}

bool	have_onlyvalid_ch(t_gm *game)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (game->map->matriz[++ i])
	{
		j = -1;
		while (game->map->matriz[i][++ j])
		{
			if (!ft_strchr("01NSEW ", game->map->matriz[i][j]))
				return (ft_err_msg("Invalid Character on map!", false));
		}
	}
	return (true);
}

bool	is_map_closed(char	**map)
{
	int	i;

	if (!is_last_column_closed(map)
		||!is_line_vertical_valid(map) || !is_first_last_valid(map))
		return (false);
	i = 0;
	while (map[i])
	{
		if (!is_line_horizontal_valid(map[i]))
			return (false);
		i ++;
	}
	return (true);
}

bool	is_last_column_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j])
		{
			if (jump_spaces(map[i][j], &j, 1))
				continue ;
			if (map[i][j] != '1')
				return (ft_err_msg("Map last column invalid!", false));
			else
				break ;
		}
		i ++;
	}
	return (true);
}
