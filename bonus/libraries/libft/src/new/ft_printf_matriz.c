/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_matriz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:05:38 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 11:05:44 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_matriz(char **to_print)
{
	int	i;

	i = 0;
	if (!to_print)
		return ;
	while (to_print[i])
	{
		write(1, "Element ->", 10);
		write(1, to_print[i], ft_strlen(to_print[i]));
		write(1, "\n", 1);
		i ++;
	}
}
