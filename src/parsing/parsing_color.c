/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:40:15 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/08 01:59:34 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

char	*get_element_info(char *line)
{
	int		j;
	int		i;
	char	*extracted;
	char	*trim;

	j = 0;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i ++;
	while (ft_isalpha(line[i]))
		i ++;
	if (line[i] == ' ' || line[i] == '\t')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i ++;
	}
	j = i;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != '\t')
		i ++;
	extracted = ft_substr(line, j, i - j);
	trim = ft_strtrim(extracted, " ");
	free(extracted);
	return (trim);
}

void	get_texture_and_color(t_vars *vars, char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (lines[i] && ft_strstr(lines[i], "NO ") && !vars->no_texture)
			vars->no_texture = get_element_info(lines[i]);
		else if (lines[i] && ft_strstr(lines[i], "SO ") && !vars->so_texture)
			vars->so_texture = get_element_info(lines[i]);
		else if (lines[i] && ft_strstr(lines[i], "WE ") && !vars->we_texture)
			vars->we_texture = get_element_info(lines[i]);
		else if (lines[i] && ft_strstr(lines[i], "EA ") && !vars->ea_texture)
			vars->ea_texture = get_element_info(lines[i]);
		else if (lines[i] && ft_strstr(lines[i], "F ")
			&& (vars->floor_color[0] == -1
				&& vars->floor_color[1] == -1
				&& vars->floor_color[2] == -1))
			parse_color(&lines[i][2], vars->floor_color);
		else if (lines[i] && ft_strstr(lines[i], "C ")
			&& (vars->ceiling_color[0] == -1
				&& vars->ceiling_color[1] == -1
				&& vars->ceiling_color[2] == -1))
			parse_color(&lines[i][2], vars->ceiling_color);
		i++;
	}
}
