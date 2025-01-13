/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ca_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:34:40 by rpambo            #+#    #+#             */
/*   Updated: 2025/01/12 11:34:46 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

bool	can_player_move(t_vars *vars, double new_x, double new_y)
{
	if (vars->map.worldmap[(int)new_y][(int)new_x] == '1')
		return (false);
	return (true);
}
