/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:47:57 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 13:46:58 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	jump_spaces(char ch, int *j, int backwards)
{
	if (ch == ' ' && !backwards)
	{
		(*j)++;
		return (true);
	}
	if (ch == ' ' && backwards)
	{
		(*j)--;
		return (true);
	}
	return (false);
}

int	my_mlx_get_pixel(t_text *textr, int x, int y, int index)
{
	char	*data_adr;
	int		offset;

	if (x >= textr->width[index] || y >= textr->height[index])
		return (0);
	data_adr = textr->data[index];
	offset = (y * textr->line_length[index])
		+ (x * (textr->bits_per_pixel[index] / 8));
	return (*(int *)(data_adr + offset));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < SCREENWIDTH && y >= 0 && y < SCREENHEIGHT)
	{
		dst = data->addr + (y * data->line_length + x
				*(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	skip_whitespace(char *color_str)
{
	while (*color_str == ' ' || *color_str == '\t')
		color_str++;
}

bool	is_spaced(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if ((ft_isalpha(str[i])
				|| ft_isdigit(str[i]))
			&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
			return (true);
		i++;
	}
	return (false);
}
