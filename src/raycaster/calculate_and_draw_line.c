/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_and_draw_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:28:36 by rpambo            #+#    #+#             */
/*   Updated: 2025/01/11 22:25:00 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	calculate_line_height_and_bounds(t_draw_params *params)
{
	params->lineheight = (int)(SCREENHEIGHT / params->perpwalldist);
	params->drawstart = -params->lineheight / 2 + SCREENHEIGHT / 2;
	params->drawend = params->lineheight / 2 + SCREENHEIGHT / 2;
	if (params->drawstart < 0)
		params->drawstart = 0;
	if (params->drawend >= SCREENHEIGHT)
		params->drawend = SCREENHEIGHT - 1;
}

void	calculate_wall_position(t_draw_params *params)
{
	if (params->vars->ray.side_hit == 0)
		params->wallx = params->vars->player.posy
			+ params->perpwalldist * params->vars->ray.ray_dir_y;
	else
		params->wallx = params->vars->player.posx
			+ params->perpwalldist * params->vars->ray.ray_dir_x;
	params->wallx -= floor(params->wallx);
}

void	calculate_texture_x(t_draw_params *params)
{
	t_text	*textr;
	int		texture_index;

	textr = &params->vars->textr;
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
			texture_index = 0;
		else
			texture_index = 1;
	}
	params->texx = (int)(params->wallx * textr->width[texture_index]);
	if ((params->vars->ray.side_hit == 0 && params->vars->ray.ray_dir_x > 0)
		|| (params->vars->ray.side_hit == 1 && params->vars->ray.ray_dir_y < 0))
		params->texx = textr->width[texture_index] - params->texx - 1;
}

void	draw_line_texture(t_draw_params *params)
{
	int		y;
	t_text	*textr;
	int		texture_index;

	textr = &params->vars->textr;
	texture_index = set_texture_index(params);
	y = params->drawstart;
	while (y < params->drawend)
	{
		params->texy = (y * 256 - SCREENHEIGHT * 128
				+ params->lineheight * 128);
		params->texy = (params->texy * textr->height[texture_index])
			/ params->lineheight;
		params->texy = params->texy / 256;
		params->color = my_mlx_get_pixel(
				textr, params->texx, params->texy, texture_index);
		my_mlx_pixel_put(&params->vars->img, params->x, y, params->color);
		y++;
	}
}

void	calculate_and_draw_line(t_draw_params *params)
{
	calculate_line_height_and_bounds(params);
	calculate_wall_position(params);
	calculate_texture_x(params);
	draw_line_texture(params);
}
