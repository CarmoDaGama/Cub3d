/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrizdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:17 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 11:01:25 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrizdup(char **to_dup)
{
	int		i;
	char	**duplicated;

	if (!to_dup)
		return (NULL);
	duplicated = ft_calloc(sizeof(char *), ft_matrizlen(to_dup) + 1);
	if (!duplicated)
		return (NULL);
	i = 0;
	while (to_dup[i])
	{
		duplicated[i] = ft_strdup(to_dup[i]);
		i ++;
	}
	duplicated[i] = NULL;
	return (duplicated);
}
