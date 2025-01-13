/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:08:41 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/08 01:53:43 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	free_map(t_map *map)
{
	int	i;

	if (map->worldmap)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->worldmap[i])
			{
				free(map->worldmap[i]);
				map->worldmap[i] = NULL;
			}
			i++;
		}
		free(map->worldmap);
		map->worldmap = NULL;
	}
}

static void	free_texture_vars(t_vars *vars)
{
	if (vars->no_texture)
	{
		free(vars->no_texture);
		vars->no_texture = NULL;
	}
	if (vars->so_texture)
	{
		free(vars->so_texture);
		vars->so_texture = NULL;
	}
	if (vars->we_texture)
	{
		free(vars->we_texture);
		vars->we_texture = NULL;
	}
	if (vars->ea_texture)
	{
		free(vars->ea_texture);
		vars->ea_texture = NULL;
	}
}

static void	destroy_mlx_image(void *mlx, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (vars->textr.textures[i])
		{
			mlx_destroy_image(mlx, vars->textr.textures[i]);
			vars->textr.textures[i] = NULL;
		}
		i++;
	}
}

void	free_vars(t_vars *vars)
{
	if (vars->mlx)
	{
		if (vars->win)
		{
			mlx_clear_window(vars->mlx, vars->win);
			mlx_destroy_window(vars->mlx, vars->win);
			vars->win = NULL;
		}
		destroy_mlx_image(vars->mlx, vars);
		if (vars->img.img)
		{
			mlx_destroy_image(vars->mlx, vars->img.img);
			vars->img.img = NULL;
		}
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
	}
	free_texture_vars(vars);
	free_map(&vars->map);
	free(vars);
}
