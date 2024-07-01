/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:00:31 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 15:53:29 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_number(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + 1] != '\0')
	{
		i++;
	}
	while (av[i] && ft_isdigit(av[i]))
	{
		i++;
	}
	if (av[i] != '\0' && !ft_isdigit(av[i]))
	{
		return (0);
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int		neg;
	int		i;
	long	nb;

	nb = 0;
	neg = 1;
	i = 0;
	if (str[i] == '+')
	{
		i++;
	}
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * neg);
}

static int	ft_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_zero(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]))
	{
		i++;
	}
	while (av[i] && av[i] == '0')
	{
		i++;
	}
	if (av[i] != '\0')
	{
		return (0);
	}
	return (1);
}

int	ft_valid(char **av)
{
	int	i;
	int	j;

	if (av[1] == NULL || av[1][0] == '\0')
		return (0);
	j = 0;
	i = 1;
	while (av[i])
	{
		if (!ft_number(av[i]))
		{
			return (0);
		}
		j += ft_zero(av[i]);
		i++;
	}
	if (j > 1)
	{
		return (0);
	}
	if (ft_duplicate(av))
	{
		return (0);
	}
	return (1);
}
