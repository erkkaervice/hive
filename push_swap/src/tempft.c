/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:22:48 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/27 14:19:31 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14)
		|| (c == 32))
	{
		return (1);
	}
	return (0);
}

int	ft_abs(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	return (n);
}

long	ft_atoi(const char *str)
{
	int		isneg;
	int		i;
	long	nb;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
	{
		i++;
	}
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}
