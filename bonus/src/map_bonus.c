/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:23:13 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 14:23:16 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	extract_map(t_game *game, char **scene)
{
	int	start;

	start = find_starting_point(scene);
	game->map->matriz = ft_matrizdup(&scene[start]);
	if (game->map->matriz[0] == NULL)
		return ;
	make_map_rectangle(game);
}

int	find_starting_point(char **scene)
{
	int	i;
	int	qt;

	i = 0;
	qt = 0;
	while (scene[i])
	{
		if (scene[i] && (ft_strstr(scene[i], "NO ")
				|| ft_strstr(scene[i], "SO ") || ft_strstr(scene[i], "WE ")
				|| ft_strstr(scene[i], "EA ") || ft_strstr(scene[i], "F ")
				|| ft_strstr(scene[i], "C ")))
			qt ++;
		i ++;
		if (qt == 6)
			break ;
	}
	while (scene[i] && is_empty_line(scene[i]))
		i ++;
	return (i);
}

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (false);
		i ++;
	}
	return (true);
}

void	make_map_rectangle(t_game *game)
{
	int		big_line;
	int		i;
	char	**matriz_dup;

	big_line = ft_matriz_big_line(game->map->matriz);
	matriz_dup = ft_matrizdup(game->map->matriz);
	i = 0;
	while (matriz_dup[i])
	{
		free(game->map->matriz[i]);
		game->map->matriz[i] = NULL;
		game->map->matriz[i] = create_spaced_line(matriz_dup[i], big_line - 1);
		i ++;
	}
	ft_free_matriz(matriz_dup);
}

char	*create_spaced_line(char *line, int big_line)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (big_line + 1));
	if (!ret)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		ret[j] = line[i];
		i ++;
		j ++;
	}
	while (j < big_line)
	{
		ret[j] = ' ';
		j ++;
	}
	ret[j] = '\0';
	return (ret);
}
