/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:05:13 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 15:05:18 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	get_txtr_size(int *height, int *width, t_game *game)
{
	if (game->ray->side_hit == 1 && game->ray->ray_dir_y < 0)
	{
		*height = game->textr->txt_height[0];
		*width = game->textr->txt_width[0];
	}
	else if (game->ray->side_hit == 1 && game->ray->ray_dir_y > 0)
	{
		*height = game->textr->txt_height[1];
		*width = game->textr->txt_width[1];
	}
	else if (game->ray->side_hit == 0 && game->ray->ray_dir_x < 0)
	{
		*height = game->textr->txt_height[2];
		*width = game->textr->txt_width[2];
	}
	else
	{
		*height = game->textr->txt_height[3];
		*width = game->textr->txt_width[3];
	}
}

void	get_wall_height_and_draw(t_game *game, t_ray *ray, int x)
{
	t_texture	*t;
	int			txt_w;
	int			txt_h;

	get_txtr_size(&txt_h, &txt_w, game);
	t = game->textr;
	t->r_line_len = (int)(HEIGHT / ray->wall_ppclr_dstc);
	t->txt_x = (int)(t->wall_hit_pos * (double)txt_w);
	t->step = 1.0 * txt_h / t->r_line_len;
	t->text_pos = (t->r_first_point - HEIGHT / 2 + t->r_line_len / 2) * t->step;
	get_render_points(game);
	get_wall_hit_pos(game);
	if (ray->side_hit == 1 && ray->ray_dir_y < 0)
		draw_texture(game, x, 0, txt_h);
	else if (ray->side_hit == 1 && ray->ray_dir_y > 0)
		draw_texture(game, x, 1, txt_h);
	else if (ray->side_hit == 0 && ray->ray_dir_x < 0)
		draw_texture(game, x, 2, txt_h);
	else
		draw_texture(game, x, 3, txt_h);
}

void	draw_texture(t_game *game, int x, int img_index, int txt_h)
{
	int			y;
	int			color;
	t_texture	*t;

	t = game->textr;
	y = t->r_first_point;
	while (y < t->r_last_point)
	{
		t->txt_y = (int)t->text_pos & (txt_h - 1);
		t->text_pos += t->step;
		color = my_mlx_get_pixel(game, t->txt_x, t->txt_y, img_index);
		my_mlx_pixel_put(game->mlx, x, y, color);
		y ++;
	}
}

void	get_wall_hit_pos(t_game *game)
{
	t_ray		*r;
	t_texture	*t;

	r = game->ray;
	t = game->textr;
	if (r->side_hit == 0)
		t->wall_hit_pos = r->plyr_y + r->wall_ppclr_dstc * r->ray_dir_y;
	else
		t->wall_hit_pos = r->plyr_x + r->wall_ppclr_dstc * r->ray_dir_x;
	t->wall_hit_pos -= floor(t->wall_hit_pos);
}

void	get_render_points(t_game *game)
{
	t_texture	*t;

	t = game->textr;
	t->r_first_point = -t->r_line_len / 2 + HEIGHT / 2;
	if (t->r_first_point < 0)
		t->r_first_point = 0;
	t->r_last_point = t->r_line_len / 2 + HEIGHT / 2;
	if (t->r_last_point >= HEIGHT)
		t->r_last_point = HEIGHT - 1;
}
