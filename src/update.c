/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:56:35 by rpambo            #+#    #+#             */
/*   Updated: 2025/01/12 11:30:27 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

void	update_player_position(t_vars *vars, int key_pressed)
{
	mlx_clear_window(vars->mlx, vars->win);
	draw_frame(vars);
	if (key_pressed == 65307)
		exit(0);
	if (key_pressed == 100)
		move_right(vars);
	if (key_pressed == 65363)
		rotate_player(vars, vars->player.rotspeed);
	if (key_pressed == 115)
		move_down(vars);
	if (key_pressed == 119)
		move_up(vars);
	if (key_pressed == 97)
		move_left(vars);
	if (key_pressed == 65361)
		rotate_player(vars, -vars->player.rotspeed);
}
