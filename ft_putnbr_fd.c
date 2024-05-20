/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:29:41 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/20 14:33:59 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		if (ft_putnbr_fd(n / 10, fd) == -1)
			return (-1);
		if (ft_putchar_fd('8', fd) == -1)
			return (-1);
		return (0);
	}
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
	{
		if (ft_putnbr_fd(n / 10, fd) == -1)
			return (-1);
	}
	if (ft_putchar_fd(n % 10 + '0', fd) == -1)
		return (-1);
	return (0);
}
