/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:25:01 by rpambo            #+#    #+#             */
/*   Updated: 2024/11/30 22:39:11 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	init_texture(t_text *textr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		textr->textures[i] = NULL;
		textr->width[i] = 0;
		textr->height[i] = 0;
		i++;
	}
	textr->wall_hit_pos = 0.0;
	textr->step = 0.0;
	textr->text_pos = 0.0;
	textr->r_first_point = 0;
	textr->r_last_point = 0;
	textr->r_line_len = 0;
	textr->txt_x = 0;
	textr->txt_y = 0;
}

static void	init_map(t_map *map)
{
	map->worldmap = NULL;
	map->width = 0;
	map->height = 0;
}

static void	init_player(t_ply *player)
{
	player->posx = 0.0;
	player->posy = 0.0;
	player->dirx = 0.0;
	player->diry = 0.0;
	player->planex = 0.0;
	player->planey = 0.0;
	player->movespeed = 0.07;
	player->rotspeed = 0.03;
}

static void	init_ray(t_ray *ray)
{
	ray->cam_x = 0.0;
	ray->ray_dir_x = 0.0;
	ray->ray_dir_y = 0.0;
	ray->delta_dstc_x = 0.0;
	ray->delta_dstc_y = 0.0;
	ray->side_dstc_x = 0.0;
	ray->side_dstc_y = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_hit = 0;
	ray->wall_ppclr_dstc = 0.0;
	ray->side = 0;
	ray->walldist = 0.0;
}

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img.img = NULL;
	vars->img.addr = NULL;
	vars->img.bits_per_pixel = 0;
	vars->img.line_length = 0;
	vars->img.endian = 0;
	vars->x = 0;
	vars->y = 0;
	init_player(&vars->player);
	init_map(&vars->map);
	init_ray(&vars->ray);
	init_texture(&vars->textr);
	init_textur(vars);
	init_colors(vars);
}
