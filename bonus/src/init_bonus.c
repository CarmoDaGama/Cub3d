/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:57:26 by cgama             #+#    #+#             */
/*   Updated: 2025/01/11 13:25:08 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

int	init_game_struct(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	ft_bzero(game->map, sizeof(t_map));
	game->map->cc_rgb[0] = -1;
	game->map->cc_rgb[1] = -1;
	game->map->cc_rgb[2] = -1;
	game->map->fc_rgb[0] = -1;
	game->map->fc_rgb[1] = -1;
	game->map->fc_rgb[2] = -1;
	game->ray = malloc(sizeof(t_ray));
	ft_bzero(game->ray, sizeof(t_ray));
	game->ray->mov_speed = 0.07;
	game->mlx = malloc(sizeof(t_mlx));
	game->mm = malloc(sizeof(t_minmap));
	ft_bzero(game->mm, sizeof(t_minmap));
	game->textr = malloc(sizeof(t_texture));
	ft_bzero(game->textr, sizeof(t_texture));
	init_firearm_struct(game);
	if (init_game_error_handling(game))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	get_texture_pointers(t_game *game)
{
	t_texture	*t;
	t_mlx		*cnt;

	t = game->textr;
	cnt = game->mlx->cnt;
	t->texture[0] = mlx_xpm_file_to_image(cnt, game->map->ntex,
			&game->textr->txt_width[0], &game->textr->txt_height[0]);
	t->texture[1] = mlx_xpm_file_to_image(cnt, game->map->stex,
			&game->textr->txt_width[1], &game->textr->txt_height[1]);
	t->texture[2] = mlx_xpm_file_to_image(cnt, game->map->wtex,
			&game->textr->txt_width[2], &game->textr->txt_height[2]);
	t->texture[3] = mlx_xpm_file_to_image(cnt, game->map->etex,
			&game->textr->txt_width[3], &game->textr->txt_height[3]);
	t->texture[4] = mlx_xpm_file_to_image(cnt, "./bonus/textures/gun1.xpm",
			&game->textr->txt_width[4], &game->textr->txt_height[4]);
	t->texture[5] = mlx_xpm_file_to_image(cnt, "./bonus/textures/gun2.xpm",
			&game->textr->txt_width[5], &game->textr->txt_height[5]);
	t->texture[6] = mlx_xpm_file_to_image(cnt, "./bonus/textures/aim.xpm",
			&game->textr->txt_width[6], &game->textr->txt_height[6]);
	if (t->texture[0] == NULL || t->texture[1] == NULL
		|| t->texture[2] == NULL || t->texture[3] == NULL
		|| t->texture[4] == NULL || t->texture[5] == NULL
		|| t->texture[6] == NULL)
		ft_err_msg("Failed texture image init", EXIT_FAILURE);
}

int	init_game_error_handling(t_game *game)
{
	if (!game || !game->firearm || !game->map || !game->mlx
		|| !game->mm || !game->ray || !game->textr)
	{
		if (game->firearm)
			free(game->firearm);
		if (game->map)
			free(game->map);
		if (game->mlx)
			free(game->mlx);
		if (game->mm)
			free(game->mm);
		if (game->ray)
			free(game->ray);
		if (game->textr)
			free(game->textr);
		if (game)
			free(game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
