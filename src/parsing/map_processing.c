/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:08:12 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 18:08:58 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static char	*create_spaced_line(char *line, int big_line)
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

static int	create_new_map_rows(t_vars *vars, char **new_map, int big_line)
{
	int	i;

	i = 0;
	while (vars->map.worldmap[i])
	{
		new_map[i] = create_spaced_line(vars->map.worldmap[i], big_line - 1);
		if (!new_map[i])
		{
			ft_err_msg("Error: Failedtocreatespacedlineformaprow.\n", true);
			while (--i >= 0)
				free(new_map[i]);
			free(new_map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (i);
}

void	make_map_rectangle(t_vars *vars)
{
	int		big_line;
	int		i;
	char	**new_map;

	big_line = ft_matriz_big_line(vars->map.worldmap);
	new_map = malloc(sizeof(char *) * (ft_matrizlen(vars->map.worldmap) + 1));
	if (!new_map)
	{
		ft_err_msg("Error: Failed to allocate memory for new map.\n", true);
		exit(EXIT_FAILURE);
	}
	i = create_new_map_rows(vars, new_map, big_line);
	new_map[i] = NULL;
	ft_free_matriz(vars->map.worldmap);
	vars->map.worldmap = new_map;
}
