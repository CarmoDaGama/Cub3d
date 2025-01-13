/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:55:36 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/02 23:54:07 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

void	rays_direction(t_vars *vars, int x)
{
	vars->ray.cam_x = 2 * x / (double)SCREENWIDTH - 1;
	vars->ray.ray_dir_x = vars->player.dirx
		+ vars->player.planex * vars->ray.cam_x;
	vars->ray.ray_dir_y = vars->player.diry
		+ vars->player.planey * vars->ray.cam_x;
}

void	delta_dstc(t_vars *vars)
{
	if (vars->ray.ray_dir_x == 0)
		vars->ray.delta_dstc_x = INT_MAX;
	else
		vars->ray.delta_dstc_x = fabs(1 / vars->ray.ray_dir_x);
	if (vars->ray.ray_dir_y == 0)
		vars->ray.delta_dstc_y = INT_MAX;
	else
		vars->ray.delta_dstc_y = fabs(1 / vars->ray.ray_dir_y);
}

void	step_increment(t_vars *vars)
{
	if (vars->ray.ray_dir_x < 0)
		vars->ray.step_x = -1;
	else
		vars->ray.step_x = 1;
	if (vars->ray.step_x == 1)
		vars->ray.side_dstc_x = (
				vars->ray.map_x + 1.0 - vars->player.posx)
			* vars->ray.delta_dstc_x;
	else
		vars->ray.side_dstc_x = (
				vars->player.posx - vars->ray.map_x)
			* vars->ray.delta_dstc_x;
	if (vars->ray.ray_dir_y < 0)
		vars->ray.step_y = -1;
	else
		vars->ray.step_y = 1;
	if (vars->ray.step_y == 1)
		vars->ray.side_dstc_y = (
				vars->ray.map_y + 1.0 - vars->player.posy)
			* vars->ray.delta_dstc_y;
	else
		vars->ray.side_dstc_y = (
				vars->player.posy - vars->ray.map_y)
			* vars->ray.delta_dstc_y;
}

void	draw_floor_and_ceiling(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			if (y < SCREENHEIGHT / 2)
				my_mlx_pixel_put(&vars->img, x, y, vars->ceiling_color_hex);
			else
				my_mlx_pixel_put(&vars->img, x, y, vars->floor_color_hex);
			x++;
		}
		y++;
	}
}

void	launch_ray(t_vars *vars)
{
	while (1)
	{
		if (vars->ray.side_dstc_x < vars->ray.side_dstc_y)
		{
			vars->ray.side_dstc_x += vars->ray.delta_dstc_x;
			vars->ray.map_x += vars->ray.step_x;
			vars->ray.side_hit = 0;
		}
		else
		{
			vars->ray.side_dstc_y += vars->ray.delta_dstc_y;
			vars->ray.map_y += vars->ray.step_y;
			vars->ray.side_hit = 1;
		}
		if (vars->map.worldmap[vars->ray.map_y][vars->ray.map_x] == '1')
		{
			if (vars->ray.side_hit == 0)
				vars->ray.wall_ppclr_dstc = vars->ray.side_dstc_x
					- vars->ray.delta_dstc_x;
			else
				vars->ray.wall_ppclr_dstc = vars->ray.side_dstc_y
					- vars->ray.delta_dstc_y;
			break ;
		}
	}
}
