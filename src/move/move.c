/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:22:59 by rpambo            #+#    #+#             */
/*   Updated: 2025/01/12 11:40:00 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

void	rotate_player(t_vars *vars, double rotspeed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = vars->player.dirx;
	vars->player.dirx = vars->player.dirx * cos(rotspeed)
		- vars->player.diry * sin(rotspeed);
	vars->player.diry = olddirx * sin(rotspeed)
		+ vars->player.diry * cos(rotspeed);
	oldplanex = vars->player.planex;
	vars->player.planex = vars->player.planex * cos(rotspeed)
		- vars->player.planey * sin(rotspeed);
	vars->player.planey = oldplanex * sin(rotspeed)
		+ vars->player.planey * cos(rotspeed);
}

void	move_up(t_vars *vars)
{
	double	new_x;
	double	new_y;

	new_x = vars->player.posx
		+ (vars->player.dirx * vars->player.movespeed);
	new_y = vars->player.posy
		+ (vars->player.diry * vars->player.movespeed);
	if (can_player_move(vars, new_x, new_y))
	{
		vars->player.posx = new_x;
		vars->player.posy = new_y;
	}
}

void	move_down(t_vars *vars)
{
	double	new_x;
	double	new_y;

	new_x = vars->player.posx
		- (vars->player.dirx * vars->player.movespeed);
	new_y = vars->player.posy
		- (vars->player.diry * vars->player.movespeed);
	if (can_player_move(vars, new_x, new_y))
	{
		vars->player.posx = new_x;
		vars->player.posy = new_y;
	}
}

void	move_left(t_vars *vars)
{
	double	new_x;
	double	new_y;

	new_x = vars->player.posx
		- (vars->player.planex * vars->player.movespeed);
	new_y = vars->player.posy
		- (vars->player.planey * vars->player.movespeed);
	if (can_player_move(vars, new_x, new_y))
	{
		vars->player.posx = new_x;
		vars->player.posy = new_y;
	}
}

void	move_right(t_vars *vars)
{
	double	new_x;
	double	new_y;

	new_x = vars->player.posx
		+ (vars->player.planex * vars->player.movespeed);
	new_y = vars->player.posy
		+ (vars->player.planey * vars->player.movespeed);
	if (can_player_move(vars, new_x, new_y))
	{
		vars->player.posx = new_x;
		vars->player.posy = new_y;
	}
}
