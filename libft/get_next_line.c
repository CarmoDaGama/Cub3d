/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:40:46 by rpambo            #+#    #+#             */
/*   Updated: 2024/06/19 22:40:51 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr_gnl(stash, '\n'))
	{
		buffer = ft_calloc_gnl(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer)
		{
			if (stash)
				free(stash);
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		stash = ft_strjoin_gnl(stash, buffer);
	}
	return (stash);
}

char	*extract_excedent(char *stash)
{
	int		i;
	char	*extract_line;

	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i ++;
	if (ft_strchr_gnl(stash, '\n'))
		i ++;
	extract_line = ft_calloc_gnl(sizeof(char), i + 1);
	if (!extract_line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		extract_line[i] = stash[i];
		i ++;
	}
	if (stash[i] == '\n')
		extract_line[i++] = '\n';
	extract_line[i] = '\0';
	return (extract_line);
}

char	*update_stash(char *old_stash)
{
	int		i;
	int		j;
	int		len;
	char	*stash_update;

	i = 0;
	while (old_stash[i] != '\0' && old_stash[i] != '\n')
		i++;
	if (!old_stash || !ft_strchr_gnl(old_stash, '\n'))
	{
		free(old_stash);
		return (NULL);
	}
	len = ft_strlen_gnl(&old_stash[i] + 1);
	stash_update = ft_calloc_gnl(sizeof(char), len + 1);
	if (!stash_update)
		return (NULL);
	j = 0;
	i++;
	while (old_stash[i] != '\0')
		stash_update[j++] = old_stash[i++];
	stash_update[j] = '\0';
	free(old_stash);
	return (stash_update);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_excedent(stash);
	stash = update_stash(stash);
	return (line);
}
