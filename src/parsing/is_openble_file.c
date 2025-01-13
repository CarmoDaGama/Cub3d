/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_openble_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:27:07 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 10:33:51 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static bool	check_extension(char *path, char *extension,
		int ext_len, char *err_msg)
{
	int	len;

	len = ft_strlen(path);
	if (len <= ext_len
		|| ft_strncmp(extension, &path[len - ext_len], ext_len) != 0)
	{
		ft_err_msg(err_msg, false);
		return (false);
	}
	return (true);
}

bool	is_openble_file(char *path, char *extension, int ext_len)
{
	int		fd;
	char	*err_msg;

	if (!path || (extension && ext_len <= 0))
		return (ft_err_msg("Invalid argumentspassedtois_openble_file!", false));
	err_msg = ft_strjoin(path, " - Not a valid file!");
	if (!err_msg)
		return (ft_err_msg("Memory allocation failed!", false));
	if (extension && !check_extension(path, extension, ext_len, err_msg))
		return (free(err_msg), false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_err_msg(err_msg, false);
		return (free(err_msg), false);
	}
	close(fd);
	return (free(err_msg), true);
}
