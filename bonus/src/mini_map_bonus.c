/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:58:46 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 11:58:49 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	draw_mini_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->mm->m_pressed == 1)
		game->mm->tile_size = 30;
	else
		game->mm->tile_size = 10;
	while (game->map->matriz[i])
	{
		j = 0;
		while (game->map->matriz[i][j])
		{
			render_mini_map(game, j, i);
			j++;
		}
		i++;
	}
	render_mini_map_player(game);
}

void	render_mini_map(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	ts;

	ts = game->mm->tile_size;
	i = 0;
	while (i < ts)
	{
		j = 0;
		while (j < ts)
		{
			if (game->map->matriz[y][x] == '1')
				my_mlx_pixel_put(game->mlx, (x * ts) + j, (y * ts) + i,
					0xFFFFFF);
			else if (ft_strchr("NSEW0", game->map->matriz[y][x]))
				my_mlx_pixel_put(game->mlx, (x * ts) + j, (y * ts) + i,
					0xFF0000);
			j++;
		}
		i++;
	}
}

void	render_mini_map_player(t_game *game)
{
	int	radius;
	int	x;
	int	y;

	if (!game->mm->m_pressed)
		radius = 2;
	else
		radius = 5;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				my_mlx_pixel_put(game->mlx,
					(game->ray->plyr_x * game->mm->tile_size) + x,
					(game->ray->plyr_y * game->mm->tile_size) + y, 0x00FF00);
			}
			x ++;
		}
		y ++;
	}
}
