/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:39:47 by rpambo            #+#    #+#             */
/*   Updated: 2024/11/28 12:40:06 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

void	print_texture_paths(t_vars *vars)
{
	printf("North Texture: %s\n", vars->no_texture);
	printf("South Texture: %s\n", vars->so_texture);
	printf("West Texture: %s\n", vars->we_texture);
	printf("East Texture: %s\n", vars->ea_texture);
}

void	print_colors(t_vars *vars)
{
	int	i;

	i = 0;
	printf("Floor Color:");
	while (i < 3)
	{
		printf(" %d", vars->floor_color[i]);
		i++;
	}
	printf("\n");
	printf("Ceiling Color:");
	i = 0;
	while (i < 3)
	{
		printf(" %d", vars->ceiling_color[i]);
		i++;
	}
}

void	print_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map.worldmap[i])
	{
		j = 0;
		while (vars->map.worldmap[i][j])
		{
			printf("%c", vars->map.worldmap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
