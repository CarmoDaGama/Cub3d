/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapfile_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:16:45 by rpambo            #+#    #+#             */
/*   Updated: 2024/12/03 10:26:03 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static char	**allocate_map(int fd, int lines_count)
{
	char	**map;

	map = ft_calloc(sizeof(char *), lines_count + 1);
	if (!map)
		close(fd);
	return (map);
}

static char	**read_lines(int fd, int lines_count)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = allocate_map(fd, lines_count);
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (map);
}

char	**get_mapfile_info(char *file_path)
{
	int	fd;
	int	lines_count;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines_count = ft_fd_lines_counter(file_path);
	if (lines_count <= 0)
	{
		close(fd);
		return (NULL);
	}
	return (read_lines(fd, lines_count));
}
