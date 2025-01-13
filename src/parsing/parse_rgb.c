/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:32:35 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 13:44:19 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	count_components(char **components)
{
	int	i;

	i = 0;
	while (components[i] != NULL)
	{
		i++;
	}
	if (i != 3)
	{
		ft_free_matriz(components);
		ft_err_msg("Error: Invalidcolorformat,expectedvalues(R,G,B).", false);
		return (i);
	}
	return (i);
}

static int	validate_components(char **components)
{
	char	*ptr;
	int		i;

	i = 0;
	while (i < 3)
	{
		ptr = components[i];
		while (*ptr == ' ' || *ptr == '\t')
			ptr++;
		if (!*ptr || ft_isdigit(*ptr) == 0)
		{
			ft_free_matriz(components);
			ft_err_msg("Error: Colorcomponentsmustbevalidintegers.", false);
			return (0);
		}
		while (*ptr && ft_isdigit(*ptr))
			ptr++;
		while (*ptr == ' ' || *ptr == '\t')
			ptr++;
		i++;
	}
	return (1);
}

static int	convert_and_validate_rgb(char **components, int *color_array)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(components[0]);
	g = ft_atoi(components[1]);
	b = ft_atoi(components[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free_matriz(components);
		ft_err_msg("Error: Colorvaluesmustbebetween0and255.", false);
		return (0);
	}
	color_array[0] = r;
	color_array[1] = g;
	color_array[2] = b;
	return (1);
}

void	parse_color(char *color_str, int *color_array)
{
	int		i;
	char	**components;

	skip_whitespace(color_str);
	components = ft_split(color_str, ',');
	if (!components)
	{
		ft_err_msg("Error: Memoryallocationfailedduringcolorparsing.", true);
		return ;
	}
	i = count_components(components);
	if (i != 3)
		return ;
	i = validate_components(components);
	if (i == 0)
		return ;
	i = convert_and_validate_rgb(components, color_array);
	if (i == 0)
		return ;
	ft_free_matriz(components);
}
