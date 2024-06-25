/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:22:48 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/25 16:21:52 by eala-lah         ###   ########.fr       */
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

int	ft_abs(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	return (n);
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

int	ft_atoi(char const *str)
{
	long long int	n;
	int				sign;
	long long int	dig;

	n = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		dig = *str - '0';
		n = n * 10 + sign * dig;
		str++;
	}
	return ((int)n);
}
