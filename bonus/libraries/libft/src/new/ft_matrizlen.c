/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrizlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:04:26 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 11:04:34 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrizlen(char **to_count)
{
	int	i;

	i = 0;
	if (!to_count)
		return (0);
	while (to_count[i])
		i ++;
	return (i);
}
