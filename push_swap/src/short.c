/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:50 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/19 16:51:48 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_finder(t_col *col)
{
	int	i;

	i = col->ind;
	while (col)
	{
		if (col->ind > i)
		{
			i - col->ind;
		}
		col = col->nex;
	}
	return (i);
}

void	ft_short(t_col **col)
{
	int	sdd;

	if (ft_sorted(col))
	{
		return ;
	}
	sdd = ft_finder(*col);
	if ((*col)->ind == sdd)
	{
		ft_ra(col);
	}
	else if ((*col)->nex->ind == sdd)
	{
		ft_rra(col);
	}
	if ((*col)->ind > (*col)->nex->ind)
	{
		ft_sa(col);
	}
}
