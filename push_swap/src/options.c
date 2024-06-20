/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:00:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/20 14:21:24 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_floor(t_col **col)
{
	t_col	*tmp;
	int		i;

	tmp = *col;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	ft_heli(t_col **col)
{
	t_col	*tmp;
	int		i;
	int		tgt;

	tmp = *col;
	i = INT_MAX;
	ft_floor(col);
	tgt = tmp->pos;
	while (tmp)
	{
		if (tmp->ind < i)
		{
			i = tmp->ind;
			tgt = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tgt);
}

static int	ft_trampoline(t_col **a, int b_ind, int tgt_ind, int tgt_pos)
{
	t_col	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->ind > b_ind && tmp->ind < tgt_ind)
		{
			tgt_ind = tmp->ind;
			tgt_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (tgt_ind != INT_MAX)
		return (tgt_pos);
	tmp = *a;
	while (tmp)
	{
		if (tmp->ind < tgt_ind)
		{
			tgt_ind = tmp->ind;
			tgt_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tgt_pos);
}

void	ft_aim(t_col **a, t_col **b)
{
	t_col	*tmp;
	int		tgt_pos;

	tmp = *b;
	ft_floor(a);
	ft_floor(b);
	tgt_pos = 0;
	while (tmp)
	{
		tgt_pos = ft_trampoline(a, tmp->ind, INT_MAX, tgt_pos);
		tmp->tgt = tgt_pos;
		tmp = tmp->next;
	}
}
