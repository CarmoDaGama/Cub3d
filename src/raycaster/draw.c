/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:53:07 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/02 22:59:38 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

static void	clear_image(t_data *img, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

/*
void	draw_line(t_data *img, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
	{
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}*/

int	draw_frame(t_vars *vars)
{
	int				x;
	t_draw_params	params;

	clear_image(&vars->img, SCREENWIDTH, SCREENHEIGHT, 0x000000);
	draw_floor_and_ceiling(vars);
	x = 0;
	while (x < SCREENWIDTH)
	{
		vars->ray.map_x = (int)vars->player.posx;
		vars->ray.map_y = (int)vars->player.posy;
		rays_direction(vars, x);
		delta_dstc(vars);
		step_increment(vars);
		launch_ray(vars);
		params.x = x;
		params.perpwalldist = vars->ray.wall_ppclr_dstc;
		params.vars = vars;
		calculate_and_draw_line(&params);
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
