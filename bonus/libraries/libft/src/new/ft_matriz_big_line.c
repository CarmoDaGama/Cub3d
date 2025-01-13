/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matriz_big_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:00:59 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 11:05:26 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matriz_big_line(char **matriz)
{
	int	size;
	int	i;

	if (!matriz)
		return (0);
	size = (int)ft_strlen(matriz[0]);
	i = 0;
	while (matriz[i])
	{
		if ((int)ft_strlen(matriz[i]) > size)
			size = ft_strlen(matriz[i]);
		i ++;
	}
	return (size);
}
