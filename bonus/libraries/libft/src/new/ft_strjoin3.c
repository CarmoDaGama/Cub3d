/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:43 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 11:06:19 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char *s1, char *s2, char *s3, int flag)
{
	char	*tmp;
	char	*s2_new;
	char	*ret;

	ret = ft_strjoin("\"", s2);
	s2_new = ft_strjoin(ret, "\"");
	free(ret);
	tmp = ft_strjoin(s1, s2_new);
	free(s2_new);
	ret = ft_strjoin(tmp, s3);
	free(tmp);
	if (flag == 1 || flag == 4 || flag == 5)
		free(s1);
	if (flag == 2 || flag == 4 || flag == 6)
		free(s2);
	if (flag == 3 || flag == 5 || flag == 6)
		free(s3);
	return (ret);
}
