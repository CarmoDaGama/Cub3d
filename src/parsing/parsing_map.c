/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:03:46 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 18:06:02 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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

void	extract_map(t_vars *vars, char **scene)
{
	int	start;

	start = find_starting_point(scene);
	if (start == -1)
	{
		ft_err_msg("Error: Failed to find map starting point.", true);
		return ;
	}
	vars->map.worldmap = ft_matrizdup(&scene[start]);
	if (!vars->map.worldmap || vars->map.worldmap[0] == NULL)
	{
		ft_err_msg("Error: Failed to extract map or map is empty.", true);
		if (vars->map.worldmap)
			ft_free_matriz(vars->map.worldmap);
		vars->map.worldmap = NULL;
		return ;
	}
	make_map_rectangle(vars);
}
