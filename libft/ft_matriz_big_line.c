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
