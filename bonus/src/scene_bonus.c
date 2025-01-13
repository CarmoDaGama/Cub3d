/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:06:38 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 15:06:41 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

int	parse_file(t_game *game, int argc, char **argv)
{
	char	**cub;

	cub = get_mapfile_info(game, argv[1]);
	replace_tabs_to_space(cub);
	get_texture_and_color(game, cub);
	if (!is_texture_and_color_valid(game, cub)
		|| !is_openble_file(game->map->ntex, NULL, 4)
		|| !is_openble_file(game->map->stex, NULL, 4)
		|| !is_openble_file(game->map->etex, NULL, 4)
		|| !is_openble_file(game->map->wtex, NULL, 4))
		return (ft_free_matriz(cub), EXIT_FAILURE);
	extract_map(game, cub);
	if (!is_map_valid(game))
		return (ft_free_matriz(cub), EXIT_FAILURE);
	ft_free_matriz(cub);
	(void)argc;
	return (EXIT_SUCCESS);
}

char	**get_mapfile_info(t_game *game, char *file_path)
{
	char	*line;
	char	**map;
	int		i;

	if (!game)
		return (NULL);
	map = ft_calloc(sizeof(char *), ft_fd_lines_counter(file_path) + 1);
	if (!map)
		return (NULL);
	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(game->map->fd);
		if (!line || !*line)
			break ;
		map[i] = ft_strdup(line);
		free(line);
		i ++;
	}
	close(game->map->fd);
	return (map);
}

void	replace_tabs_to_space(char **cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub[i])
	{
		j = 0;
		while (cub[i][j] != '\0' && cub[i][j] != '\n')
		{
			if (cub[i][j] == '\t')
				cub[i][j] = ' ';
			j ++;
		}
		i ++;
	}
}
