/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:14:13 by cgama             #+#    #+#             */
/*   Updated: 2025/01/10 15:14:21 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_err_msg(char *msg, int int_return)
{
	ft_putendl_fd("Error!", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (int_return);
}
