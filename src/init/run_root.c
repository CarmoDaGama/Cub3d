/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_root.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:05:59 by rpambo            #+#    #+#             */
/*   Updated: 2024/11/30 23:06:59 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	run_cub(t_vars *vars)
{
	start_player_position(vars);
	draw_frame(vars);
	mlx_hook(vars->win, 2, 1L << 0, keypress, vars);
	mlx_hook(vars->win, 17, 0, close_cub, vars);
	mlx_loop(vars->mlx);
}

void	start_player_position(t_vars *vars)
{
	vars->player.posx += 0.5;
	vars->player.posy += 0.5;
	if (vars->player.direc == 'N')
	{
		set_plane_positions(vars, 0.66, 0.0);
		set_direction_positions(vars, 0.0, -1.0);
	}
	else if (vars->player.direc == 'S')
	{
		set_plane_positions(vars, -0.66, 0.0);
		set_direction_positions(vars, 0.0, 1.0);
	}
	else if (vars->player.direc == 'W')
	{
		set_plane_positions(vars, 0.0, -0.66);
		set_direction_positions(vars, -1.0, 0.0);
	}
	else if (vars->player.direc == 'E')
	{
		set_plane_positions(vars, 0.0, 0.66);
		set_direction_positions(vars, 1.0, 0.0);
	}
}

void	set_plane_positions(t_vars *vars, double plane_x, double plane_y)
{
	vars->player.planex = plane_x;
	vars->player.planey = plane_y;
}

void	set_direction_positions(t_vars *vars, double dir_x, double dir_y)
{
	vars->player.dirx = dir_x;
	vars->player.diry = dir_y;
}
