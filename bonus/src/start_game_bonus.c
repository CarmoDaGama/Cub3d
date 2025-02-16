/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:59:31 by cgama             #+#    #+#             */
/*   Updated: 2025/01/11 13:25:27 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

int	start_mlx(t_game *game)
{
	game->mlx->cnt = mlx_init();
	if (!game->mlx->cnt)
		return (ft_err_msg("mlx_init failed", EXIT_FAILURE));
	game->mlx->wnd = mlx_new_window(game->mlx->cnt, WIDTH, HEIGHT, "Cub3d");
	if (!game->mlx->wnd)
		return (ft_err_msg("mlx_new_window failed", EXIT_FAILURE));
	game->mlx->img = mlx_new_image(game->mlx->cnt, WIDTH, HEIGHT);
	game->mlx->addr = mlx_get_data_addr(game->mlx->img,
			&game->mlx->bits_per_pixel, &game->mlx->line_length,
			&game->mlx->endian);
	get_texture_pointers(game);
	return (EXIT_SUCCESS);
}

void	start_player_position(t_game *game)
{
	game->ray->plyr_x = game->map->plyr_x + 0.5;
	game->ray->plyr_y = game->map->plyr_y + 0.5;
	if (game->map->plyr_dir == 'N')
	{
		set_plane_positions(game, 0.66, 0.0);
		set_direction_positions(game, 0.0, -1.0);
	}
	else if (game->map->plyr_dir == 'S')
	{
		set_plane_positions(game, -0.66, 0.0);
		set_direction_positions(game, 0.0, 1.0);
	}
	else if (game->map->plyr_dir == 'W')
	{
		set_plane_positions(game, 0.0, -0.66);
		set_direction_positions(game, -1.0, 0.0);
	}
	else if (game->map->plyr_dir == 'E')
	{
		set_plane_positions(game, 0.0, 0.66);
		set_direction_positions(game, 1.0, 0.0);
	}
}

void	set_plane_positions(t_game *game, double plane_x, double plane_y)
{
	game->ray->plane_x = plane_x;
	game->ray->plane_y = plane_y;
}

void	set_direction_positions(t_game *game, double dir_x, double dir_y)
{
	game->ray->dir_x = dir_x;
	game->ray->dir_y = dir_y;
}
