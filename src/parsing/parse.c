/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:11:12 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 10:41:13 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

static void	replace_tabs_to_space(char **cub)
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
			j++;
		}
		i++;
	}
}

static bool	validate_textures(t_vars *vars, char **lines)
{
	return (is_texture_and_color_valid(vars, lines)
		&& is_openble_file(vars->no_texture, ".xpm", 4)
		&& is_openble_file(vars->so_texture, ".xpm", 4)
		&& is_openble_file(vars->we_texture, ".xpm", 4)
		&& is_openble_file(vars->ea_texture, ".xpm", 4));
}

int	parse_config(char *file_path, t_vars *vars)
{
	char	**lines;

	lines = get_mapfile_info(file_path);
	if (!lines)
	{
		perror("Error reading lines from file");
		exit(EXIT_FAILURE);
	}
	replace_tabs_to_space(lines);
	get_texture_and_color(vars, lines);
	if (!validate_textures(vars, lines))
	{
		ft_free_matriz(lines);
		return (EXIT_FAILURE);
	}
	extract_map(vars, lines);
	if (!is_map_valid(vars))
	{
		ft_free_matriz(lines);
		return (EXIT_FAILURE);
	}
	ft_free_matriz(lines);
	return (EXIT_SUCCESS);
}
