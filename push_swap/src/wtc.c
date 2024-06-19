/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/19 17:15:03 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_col	*ft_lobby(t_col *col)
{
	while (col && col->nex != NULL)
	{
		col = col->nex;
	}
	return (col);
}

t_col	*ft_stairs(t_col *col)
{
	while (col && col->nex && col->nex->nex != NULL)
	{
		col = col ->nex;
	}
	return (col);
}

int	ft_slinky(t_col *col)
{
	int	i;

	i = 0;
	if (!col)
	{
		return (0);
	}
	while (col)
	{
		col = col->nex;
		i++;
	}
	return (i);
}
