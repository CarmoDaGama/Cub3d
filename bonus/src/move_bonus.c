/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:09:09 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 15:09:16 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

bool	can_player_move(t_game *game, int new_x, int new_y)
{
	if (game->map->matriz[(int)game->ray->plyr_y][new_x] == '1')
		return (false);
	if (game->map->matriz[new_y][(int)game->ray->plyr_x] == '1')
		return (false);
	if (game->map->matriz[new_y][new_x] == '1')
		return (false);
	return (true);
}

void	move_up(t_game *game)
{
	double		new_x;
	double		new_y;
	static int	move_delay = 0;

	new_x = game->ray->plyr_x + (game->ray->dir_x * game->ray->mov_speed);
	new_y = game->ray->plyr_y + (game->ray->dir_y * game->ray->mov_speed);
	if (can_player_move(game, new_x, new_y))
	{
		game->ray->plyr_x = new_x;
		game->ray->plyr_y = new_y;
		if (move_delay == 10)
		{
			if (!game->firearm->move)
				game->firearm->move = 20;
			else
				game->firearm->move = 0;
			move_delay = 0;
		}
		move_delay++;
	}
}

void	move_down(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray->plyr_x - (game->ray->dir_x * game->ray->mov_speed);
	new_y = game->ray->plyr_y - (game->ray->dir_y * game->ray->mov_speed);
	if (can_player_move(game, new_x, new_y))
	{
		game->ray->plyr_x = new_x;
		game->ray->plyr_y = new_y;
	}
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray->plyr_x - (game->ray->plane_x * game->ray->mov_speed);
	new_y = game->ray->plyr_y - (game->ray->plane_y * game->ray->mov_speed);
	if (can_player_move(game, new_x, new_y))
	{
		game->ray->plyr_x = new_x;
		game->ray->plyr_y = new_y;
	}
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray->plyr_x + (game->ray->plane_x * game->ray->mov_speed);
	new_y = game->ray->plyr_y + (game->ray->plane_y * game->ray->mov_speed);
	if (can_player_move(game, new_x, new_y))
	{
		game->ray->plyr_x = new_x;
		game->ray->plyr_y = new_y;
	}
}
