/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:34:39 by rpambo            #+#    #+#             */
/*   Updated: 2024/11/30 23:04:51 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_textur(t_vars *vars)
{
	vars->no_texture = NULL;
	vars->so_texture = NULL;
	vars->we_texture = NULL;
	vars->ea_texture = NULL;
}

void	init_colors(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		vars->floor_color[i] = -1;
		vars->ceiling_color[i] = -1;
		i++;
	}
	vars->floor_color_hex = -1;
	vars->ceiling_color_hex = -1;
}
