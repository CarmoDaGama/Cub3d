/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:17:42 by rpambo            #+#    #+#             */
/*   Updated: 2024/11/30 23:22:22 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	is_map_valid(t_vars *vars)
{
	char	**m_copy;

	if (vars->map.worldmap == NULL || vars->map.worldmap[0] == NULL)
		return (ft_err_msg("Error: Empty map.", false));
	m_copy = ft_matrizdup(vars->map.worldmap);
	if (!have_onlyvalid_ch(vars) || !are_all_lines_valid(vars)
		|| !is_player_valid(vars) || !is_map_closed(m_copy))
	{
		ft_free_matriz(m_copy);
		return (false);
	}
	vars->map.height = ft_matrizlen(vars->map.worldmap);
	vars->map.width = ft_matriz_big_line(vars->map.worldmap);
	ft_free_matriz(m_copy);
	return (true);
}

bool	have_onlyvalid_ch(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map.worldmap[++i])
	{
		j = -1;
		while (vars->map.worldmap[i][++j])
		{
			if (!ft_strchr("01NSEW ", vars->map.worldmap[i][j]))
			{
				ft_err_msg("Invalid character in map!", false);
				return (false);
			}
		}
	}
	return (true);
}

bool	is_player_valid(t_vars *vars)
{
	int	i;
	int	j;
	int	qt;

	i = -1;
	qt = 0;
	while (vars->map.worldmap[++i])
	{
		j = -1;
		while (vars->map.worldmap[i][++j])
		{
			if (ft_strchr("NSEW", vars->map.worldmap[i][j]))
			{
				qt++;
				vars->player.posx = j;
				vars->player.posy = i;
				vars->player.direc = vars->map.worldmap[i][j];
			}
		}
	}
	if (qt != 1)
		return (ft_err_msg("Invalid player on map", false));
	return (true);
}

bool	is_map_closed(char **map)
{
	int	i;

	if (!is_last_column_closed(map) || !is_line_vertical_valid(map)
		|| !is_first_last_valid(map))
		return (false);
	i = 0;
	while (map[i])
	{
		if (!is_line_horizontal_valid(map[i]))
			return (false);
		i++;
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
		while (j >= 0)
		{
			if (jump_spaces(map[i][j], &j, 1))
				continue ;
			if (map[i][j] != '1')
				return (ft_err_msg("Map last column invalid!", false));
			else
				break ;
		}
		i++;
	}
	return (true);
}
