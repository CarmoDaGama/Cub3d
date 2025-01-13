/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:06:15 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/02 23:57:00 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

int	root_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (ft_err_msg("mlx_init failed", EXIT_FAILURE));
	vars->win = mlx_new_window(vars->mlx, SCREENWIDTH, SCREENHEIGHT, "Cub3D");
	if (!vars->win)
		return (ft_err_msg("mlx_new_window failed", EXIT_FAILURE));
	vars->img.img = mlx_new_image(vars->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!vars->img.img)
		return (ft_err_msg("mlx_new_image failed", EXIT_FAILURE));
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	if (!vars->img.addr)
		return (ft_err_msg("mlx_get_data_addr failed", EXIT_FAILURE));
	get_texture_pointers(vars);
	return (EXIT_SUCCESS);
}
