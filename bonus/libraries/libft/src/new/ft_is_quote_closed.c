/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quote_closed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:04:00 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 11:04:04 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_quote_closed(char *input)
{
	int	i;
	int	s_quotes;
	int	d_quotes;

	i = 0;
	s_quotes = 0;
	d_quotes = 0;
	while (input[i])
	{
		if (input[i] == '\'' && d_quotes % 2 == 0)
			s_quotes++;
		else if (input[i] == '\"' && s_quotes % 2 == 0)
			d_quotes++;
		i++;
	}
	return (s_quotes % 2 == 0 && d_quotes % 2 == 0);
}
