/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:04:09 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 15:04:17 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	rays_direction(t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->cam_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->cam_x;
}

void	delta_dstc(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dstc_x = INT_MAX;
	else
		ray->delta_dstc_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dstc_y = INT_MAX;
	else
		ray->delta_dstc_y = fabs(1 / ray->ray_dir_y);
}

void	step_increment(t_ray *ray)
{
	t_ray	*r;

	r = ray;
	r->step_x = 1;
	r->side_dstc_x = (r->map_x + 1.0 - r->plyr_x) * r->delta_dstc_x;
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dstc_x = (r->plyr_x - r->map_x) * r->delta_dstc_x;
	}
	r->step_y = 1;
	r->side_dstc_y = (r->map_y + 1 - r->plyr_y) * r->delta_dstc_y;
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dstc_y = (r->plyr_y - r->map_y) * r->delta_dstc_y;
	}
}

void	launch_ray(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dstc_x < ray->side_dstc_y)
		{
			ray->side_dstc_x += ray->delta_dstc_x;
			ray->map_x += ray->step_x;
			ray->side_hit = 0;
			ray->wall_ppclr_dstc = ray->side_dstc_x - ray->delta_dstc_x;
		}
		else
		{
			ray->side_dstc_y += ray->delta_dstc_y;
			ray->map_y += ray->step_y;
			ray->side_hit = 1;
			ray->wall_ppclr_dstc = ray->side_dstc_y - ray->delta_dstc_y;
		}
		if (map->matriz[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

int	raycaster(t_game *game)
{
	int	x;

	x = 0;
	mlx_mouse_move(game->mlx->cnt, game->mlx->wnd, WIDTH / 2, HEIGHT / 2);
	draw_floor_ceiling(game);
	while (x < WIDTH)
	{
		game->ray->map_x = (int)game->ray->plyr_x;
		game->ray->map_y = (int)game->ray->plyr_y;
		rays_direction(game->ray, x);
		delta_dstc(game->ray);
		step_increment(game->ray);
		launch_ray(game->ray, game->map);
		get_wall_height_and_draw(game, game->ray, x);
		x++;
	}
	draw_mini_map(game);
	draw_firearm(game);
	mlx_put_image_to_window(game->mlx->cnt, game->mlx->wnd,
		game->mlx->img, 0, 0);
	return (EXIT_SUCCESS);
}
