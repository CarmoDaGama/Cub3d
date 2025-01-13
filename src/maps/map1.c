/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:51:25 by rpambo            #+#    #+#             */
/*   Updated: 2024/11/30 23:26:47 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	are_all_lines_valid(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.worldmap[i])
	{
		if (is_empty_line(vars->map.worldmap[i]))
			return (ft_err_msg("Invalid line on map!", false));
		i ++;
	}
	return (true);
}

bool	is_line_horizontal_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] && line[i] != '1')
		return (ft_err_msg("Map horizontal line invalid", false));
	while (line[i])
	{
		if (ft_strchr("NSEW", line[i]))
		{
			if (line[i + 1] && line[i + 1] == ' ')
				return (ft_err_msg("Invalid Player Indication", false));
			i++;
			continue ;
		}
		if (ft_strchr("01 ", line[i]))
		{
			if ((line[i] == ' ' && line[i + 1] && line[i + 1] == '0')
				|| (line[i] == '0' && line[i + 1] && line[i + 1] == ' '))
				return (ft_err_msg("Map horizontal line invalid", false));
		}
		i++;
	}
	return (true);
}

bool	is_line_vertical_valid(char **map)
{
	int	line;
	int	chars;
	int	qt_lines;
	int	qt_chars;

	line = 0;
	chars = 0;
	qt_chars = ft_matriz_big_line(map);
	qt_lines = ft_matrizlen(map);
	while (chars < qt_chars)
	{
		if (line + 1 < qt_lines && (map[line][chars] == ' '
			&& map[line + 1][chars] == ' '))
		{
			line ++ ;
			continue ;
		}
		if (line + 1 < qt_lines && ((map[line][chars] == ' '
				&& map[line + 1][chars] == '0') || (map[line][chars] == '0'
					&& map[line + 1][chars] == ' ')))
			return (ft_err_msg("Invalid Map", false));
		if (is_line_vertical_valid_aux(&line, &chars, &qt_lines, &qt_chars))
			break ;
	}
	return (true);
}

int	is_line_vertical_valid_aux(int *l, int *ch, int *qt_l, int *qt_ch)
{
	if ((*l) == (*qt_l) && (*ch) == (*qt_ch))
		return (EXIT_FAILURE);
	(*l)++;
	if ((*l) == (*qt_l))
	{
		(*l) = 0;
		(*ch)++;
	}
	return (EXIT_SUCCESS);
}

bool	is_first_last_valid(char **map)
{
	int	last_line;
	int	j;

	last_line = ft_matrizlen(map) - 1;
	j = 0;
	while (jump_spaces(map[0][j], &j, 0))
		j ++;
	if (ft_strchr(&map[0][j], '0'))
		return (ft_err_msg("First map line invalid!", false));
	j = 0;
	while (jump_spaces(map[last_line][j], &j, 0))
		j ++;
	if (ft_strchr(&map[last_line][j], '0'))
		return (ft_err_msg("Last map line invalid!", false));
	return (true);
}
