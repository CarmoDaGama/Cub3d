/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:05:47 by cgama             #+#    #+#             */
/*   Updated: 2025/01/11 13:26:15 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	rotate_left(t_game *game, double speed)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey;

	old_dirx = game->ray->dir_x;
	old_diry = game->ray->dir_y;
	game->ray->dir_x = old_dirx * cos(-speed) - old_diry * sin(-speed);
	game->ray->dir_y = old_dirx * sin(-speed) + old_diry * cos(-speed);
	old_planex = game->ray->plane_x;
	old_planey = game->ray->plane_y;
	game->ray->plane_x = old_planex * cos(-speed) - old_planey * sin(-speed);
	game->ray->plane_y = old_planex * sin(-speed) + old_planey * cos(-speed);
}

void	rotate_right(t_game *game, double speed)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey ;

	old_dirx = game->ray->dir_x;
	old_diry = game->ray->dir_y;
	game->ray->dir_x = old_dirx * cos(speed) - old_diry * sin(speed);
	game->ray->dir_y = old_dirx * sin(speed) + old_diry * cos(speed);
	old_planex = game->ray->plane_x;
	old_planey = game->ray->plane_y;
	game->ray->plane_x = old_planex * cos(speed) - old_planey * sin(speed);
	game->ray->plane_y = old_planex * sin(speed) + old_planey * cos(speed);
}
