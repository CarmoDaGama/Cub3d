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

static int	words_counter(const char *str, char c)
{
	int	word_counter;
	int	i;

	i = 0;
	word_counter = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			word_counter ++;
		i++;
	}
	return (word_counter);
}

static int	letters_counter(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char **)malloc((words_counter(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = ft_substr(s, i, letters_counter(&s[i], c));
			if (!str[j])
				return (ft_free(str, j));
			j++;
			i += letters_counter(&s[i], c);
		}
		else
			i++;
	}
	str[j] = 0;
	return (str);
}
