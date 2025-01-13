/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:39:00 by rpambo            #+#    #+#             */
/*   Updated: 2025/01/11 22:47:40 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	set_texture_index(t_draw_params *params)
{
	int	texture_index;

	if (params->vars->ray.side_hit == 0)
	{
		if (params->vars->ray.ray_dir_x > 0)
			texture_index = 3;
		else
			texture_index = 2;
	}
	else
	{
		if (params->vars->ray.ray_dir_y > 0)
			texture_index = 1;
		else
			texture_index = 0;
	}
	return (texture_index);
}
