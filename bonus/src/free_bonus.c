/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:56:44 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 11:56:49 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	free_game(t_game *game, int to_free)
{
	free_map(game->map);
	free(game->map);
	free(game->mm);
	free(game->ray);
	free(game->firearm);
	if (to_free)
	{
		free(game->textr);
		free(game->mlx);
	}
}

void	free_mlx(t_mlx *mlx, t_game *game)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (game->textr->texture[i])
			mlx_destroy_image(game->mlx->cnt, game->textr->texture[i]);
		i++;
	}
	free(game->textr);
	mlx_destroy_window(mlx->cnt, mlx->wnd);
	mlx_destroy_image(mlx->cnt, mlx->img);
	mlx_destroy_display(mlx->cnt);
	free(mlx->cnt);
	free(mlx);
}

void	free_map(t_map *map)
{
	close(map->fd);
	free(map->stex);
	free(map->ntex);
	free(map->etex);
	free(map->wtex);
	free(map->fc_str);
	free(map->cc_str);
	ft_free_matriz(map->matriz);
}
