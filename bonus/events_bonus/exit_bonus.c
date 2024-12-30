#include "../../includes/cube_bonus.h"

int	close_cub(t_gm *game)
{
	free_game(game, 0);
	free_mlx(game->mlx, game);
	return (exit(0), 0);
}
