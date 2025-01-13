/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:22:48 by cgama             #+#    #+#             */
/*   Updated: 2025/01/11 13:23:39 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

int	key_press_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_cub(game);
	else if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game, game->ray->mov_speed);
	else if (keycode == KEY_RIGHT)
		rotate_right(game, game->ray->mov_speed);
	else if (keycode == KEY_M)
		game->mm->m_pressed = !game->mm->m_pressed;
	else if (keycode == KEY_SHIFT)
		game->firearm->fire = 1;
	return (0);
}

int	mouse_handler(int x, int y, t_game *game)
{
	static int	old_x = WIDTH / 2;

	(void) y;
	if (x < old_x)
		rotate_left(game, game->ray->mov_speed / 3);
	else if (x > old_x)
		rotate_right(game, game->ray->mov_speed / 3);
	old_x = x;
	return (0);
}

int	mouse_fire(int mousecode, int x, int y, void *param)
{
	t_game	*game;

	(void)mousecode;
	(void)x;
	(void)y;
	game = (t_game *)param;
	if (!game->firearm->fire)
		return (EXIT_FAILURE);
	game->firearm->fire = 1;
	return (EXIT_SUCCESS);
}
