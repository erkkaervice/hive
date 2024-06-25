/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:50 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/25 16:05:32 by eala-lah         ###   ########.fr       */
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
			i = col->ind;
		}
		col = col->next;
	}
	return (i);
}

void	ft_short(t_col **col)
{
	int	i;

	if (ft_sorted(*col))
	{
		return ;
	}
	i = ft_finder(*col);
	if ((*col)->ind == i)
	{
		ft_ra(col);
	}
	else if ((*col)->next->ind == i)
	{
		ft_rra(col);
	}
	if ((*col)->ind > (*col)->next->ind)
	{
		ft_sa(col);
	}
}
