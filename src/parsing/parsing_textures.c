/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:57:21 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 20:45:07 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	is_element_missing(t_vars *vars)
{
	if (!vars->no_texture
		|| !vars->so_texture || !vars->we_texture || !vars->ea_texture)
		return (true);
	if (vars->floor_color[0] == -1
		|| vars->floor_color[1] == -1
		|| vars->floor_color[2] == -1
		|| vars->ceiling_color[0] == -1
		|| vars->ceiling_color[1] == -1
		|| vars->ceiling_color[2] == -1)
		return (true);
	return (false);
}

void	convert_color_system(t_vars *vars)
{
	vars->floor_color_hex = (vars->floor_color[0] << 16)
		| (vars->floor_color[1] << 8) | vars->floor_color[2];
	vars->ceiling_color_hex = (vars->ceiling_color[0] << 16)
		| (vars->ceiling_color[1] << 8) | vars->ceiling_color[2];
}

bool	is_rgb_valid(t_vars *vars)
{
	char	*err;

	if (vars->floor_color[0] < 0 || vars->floor_color[0] > 255
		|| vars->floor_color[1] < 0 || vars->floor_color[1] > 255
		|| vars->floor_color[2] < 0 || vars->floor_color[2] > 255)
	{
		err = "Error : Floor colori values must be between 0 and 255.";
		return (ft_err_msg(err, false));
	}
	if (vars->ceiling_color[0] < 0 || vars->ceiling_color[0] > 255
		|| vars->ceiling_color[1] < 0 || vars->ceiling_color[1] > 255
		|| vars->ceiling_color[2] < 0 || vars->ceiling_color[2] > 255)
	{
		err = "Error : Ceiling color values must be between 0 and 255.";
		return (ft_err_msg(err, false));
	}
	return (true);
}

int	count_map_elements(char **m)
{
	int	i;
	int	qt;

	i = 0;
	qt = 0;
	while (m[i])
	{
		if (m[i] && (ft_strstr(m[i], "NO ") || ft_strstr(m[i], "SO ")
				|| ft_strstr(m[i], "WE ") || ft_strstr(m[i], "EA ")
				|| ft_strstr(m[i], "F ") || ft_strstr(m[i], "C ")))
		{
			qt++;
		}
		i++;
	}
	return (qt);
}

bool	is_texture_and_color_valid(t_vars *vars, char **m)
{
	int	qt;

	qt = count_map_elements(m);
	if (qt > 6)
		return (ft_err_msg("Duplicated Map Elements", false));
	if (is_spaced(vars->no_texture) || is_spaced(vars->so_texture)
		|| is_spaced(vars->we_texture) || is_spaced(vars->ea_texture))
	{
		return (ft_err_msg("Invalid Map Element, space in between", false));
	}
	if (is_element_missing(vars))
		return (ft_err_msg("Missing map element", false));
	if (!is_rgb_valid(vars))
		return (ft_err_msg("Invalid RGB color value", false));
	convert_color_system(vars);
	return (true);
}
