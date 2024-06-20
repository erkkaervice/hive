/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:22:44 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/20 13:32:27 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_dartagnan(t_col **col_a, t_col **col_b)
{
	int	cos;
	int	hit;
	int	i;

	cos = ft_slinky(*col_a);
	hit = 0;
	i = 0;
	while (cos > 6 && i < cos && hit < cos / 2)
	{
		if ((*col_a)->ind <= cos / 2)
		{
			ft_pb(col_a, col_b);
			hit++;
		}
		else
		{
			ft_ra(col_a);
		}
		i++;
	}
	while (cos - hit > 3)
	{
		ft_pb(col_a, col_b);
		hit++;
	}
}

static void	ft_rearrange(t_col **col_a)
{
	int	res;
	int	cos;

	cos = ft_slinky(col_a);
	res = ft_heli(col_a);
	if (res > cos / 2)
	{
		while (res < cos)
		{
			ft_rra(col_a);
			res--;
		}
	}
}

void	ft_sort(t_col **col_a, t_col **col_b)
{
	ft_dartagnan(col_a, col_b);
	ft_short(col_a);
	while (*col_b)
	{
		ft_aim(col_a, col_b);
		ft_PRICE(col_a, col_b);
		ft_CHEAPEST_MOVE(col_a, col_b);
	}
	if (!ft_sorted(*col_a))
	{
		ft_rearrange(col_a);
	}
}
