/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:50:00 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/20 14:14:42 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	nbr_len;

	nbr_len = ft_nbrlen(n);
	if (ft_putnbr_fd(n, 1) == -1)
		return (-1);
	return (nbr_len);
}
