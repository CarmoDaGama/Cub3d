/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valids_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:25:50 by cgama             #+#    #+#             */
/*   Updated: 2025/01/13 15:34:01 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

bool	is_element_missing(t_game *game)
{
	if (!game->map->fc_str || !game->map->cc_str || !game->map->ntex
		|| !game->map->stex || !game->map->etex || !game->map->wtex)
		return (true);
	return (false);
}

bool	is_rgb_valid(t_game *game)
{
	if (!is_color_format_valid(game->map->fc_str)
		|| !is_color_format_valid(game->map->cc_str))
	{
		return (ft_err_msg("Color element format not valid, try nbr, nbr, nbr",
				false));
	}
	extract_numbers(game->map->fc_str, game->map->fc_rgb, 0);
	extract_numbers(game->map->cc_str, game->map->cc_rgb, 0);
	if (game->map->fc_rgb[0] == -1 || game->map->fc_rgb[1] == -1
		|| game->map->fc_rgb[2] == -1 || game->map->cc_rgb[0] == -1
		|| game->map->cc_rgb[1] == -1 || game->map->cc_rgb[2] == -1)
		return (ft_err_msg("Need to have 3 colors rgb values", false));
	if (game->map->fc_rgb[0] > 255 || game->map->fc_rgb[1] > 255
		|| game->map->fc_rgb[2] > 255 || game->map->cc_rgb[0] > 255
		|| game->map->cc_rgb[1] > 255 || game->map->cc_rgb[2] > 255)
		return (ft_err_msg("Color elements exceeds 255", false));
	convert_color_system(game);
	return (true);
}

void	extract_numbers(char *str, int arr[3], int i)
{
	int	num;
	int	in_number;
	int	index;

	num = 0;
	index = 0;
	in_number = 0;
	while (str[i] && index < 3)
	{
		if (ft_isdigit(str[i]))
		{
			num = num * 10 + (str[i] - '0');
			in_number = 1;
		}
		else if (in_number)
		{
			arr[index ++] = num;
			num = 0;
			in_number = 0;
		}
		i ++;
	}
	if (in_number && index < 3)
		arr[index] = num;
}

bool	is_color_format_valid(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != ',' && str[i] != ' ')
				return (false);
			if (str[i] == ' ' && i > 0 && ft_isdigit(str[i - 1])
				&& str[i + 1] && ft_isdigit(str[i + 1]))
				return (false);
		}
		if (str[i] == ',')
			comma ++;
		i ++;
	}
	if (comma != 2)
		return (false);
	return (true);
}

void	convert_color_system(t_game *game)
{
	game->map->fc_hex = (game->map->fc_rgb[0] << 16)
		| (game->map->fc_rgb[1] << 8) | game->map->fc_rgb[2];
	game->map->cc_hex = (game->map->cc_rgb[0] << 16)
		| (game->map->cc_rgb[1] << 8) | game->map->cc_rgb[2];
}
