/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:47:23 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 10:47:25 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	run_cub(t_game *game)
{
	start_player_position(game);
	mlx_mouse_hook(game->mlx->wnd, mouse_fire, game);
	mlx_loop_hook(game->mlx->cnt, &raycaster, game);
	mlx_hook(game->mlx->wnd, 2, 1L << 0, key_press_handler, game);
	mlx_hook(game->mlx->wnd, 6, 1L << 6, mouse_handler, game);
	mlx_hook(game->mlx->wnd, 17, 0, close_cub, game);
	mlx_loop(game->mlx->cnt);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_game_struct(&game))
		return (EXIT_FAILURE);
	if (!is_argument_valid(&game, argc, argv))
		return (free_game(&game, 1), EXIT_FAILURE);
	if (parse_file(&game, argc, argv))
		return (free_game(&game, 1), EXIT_FAILURE);
	if (run_mlx(&game))
		return (ft_err_msg("Error Mlx Init", EXIT_FAILURE));
	run_cub(&game);
	return (0);
}

bool	is_argument_valid(t_game *game, int argc, char **argv)
{
	if (!argv)
		return (false);
	if (argc != 2)
		return (ft_err_msg("Invalid quantity of arguments!", false));
	if (!is_openble_file(argv[1], ".cub", 4))
		return (false);
	game->map->fd = open(argv[1], O_RDONLY);
	return (true);
}
