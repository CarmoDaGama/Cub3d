/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:08:18 by cgama             #+#    #+#             */
/*   Updated: 2025/01/11 13:24:09 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_get_pixel(t_game *game, int x, int y, int index)
{
	char		*data_adr;
	t_texture	*t;
	int			offset;
	int			max_txt_width;
	int			max_txt_height;

	max_txt_height = game->textr->txt_height[index];
	max_txt_width = game->textr->txt_width[index];
	if (x >= max_txt_width || y >= max_txt_height)
		return (0);
	t = game->textr;
	data_adr = mlx_get_data_addr(t->texture[index], &t->bits_per_pixel,
			&t->line_len, &t->endian);
	offset = (y * t->line_len) + (x * (t->bits_per_pixel / 8));
	return (*(int *)(data_adr + offset));
}

void	draw_floor_ceiling(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(game->mlx, x, y, game->map->cc_hex);
			else
				my_mlx_pixel_put(game->mlx, x, y, game->map->fc_hex);
			x ++;
		}
		y++;
	}
}
