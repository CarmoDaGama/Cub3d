/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:39:19 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 21:25:47 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	validate_texture_load(t_text *textr)
{
	if (!textr->textures[0] || !textr->textures[1]
		|| !textr->textures[2] || !textr->textures[3])
		ft_err_msg("Failed to load texture image", EXIT_FAILURE);
}

void	get_texture_pointers(t_vars *vars)
{
	t_text	*textr;

	textr = &vars->textr;
	textr->textures[0] = mlx_xpm_file_to_image(
			vars->mlx, vars->no_texture, &textr->width[0],
			&textr->height[0]);
	textr->data[0] = mlx_get_data_addr(textr->textures[0],
			&textr->bits_per_pixel[0],
			&textr->line_length[0], &textr->endian[0]);
	textr->textures[1] = mlx_xpm_file_to_image(vars->mlx, vars->so_texture,
			&textr->width[1], &textr->height[1]);
	textr->data[1] = mlx_get_data_addr(textr->textures[1],
			&textr->bits_per_pixel[1],
			&textr->line_length[1], &textr->endian[1]);
	textr->textures[2] = mlx_xpm_file_to_image(vars->mlx, vars->we_texture,
			&textr->width[2], &textr->height[2]);
	textr->data[2] = mlx_get_data_addr(textr->textures[2],
			&textr->bits_per_pixel[2],
			&textr->line_length[2], &textr->endian[2]);
	textr->textures[3] = mlx_xpm_file_to_image(vars->mlx, vars->ea_texture,
			&textr->width[3], &textr->height[3]);
	textr->data[3] = mlx_get_data_addr(textr->textures[3],
			&textr->bits_per_pixel[3],
			&textr->line_length[3], &textr->endian[3]);
	validate_texture_load(textr);
}
