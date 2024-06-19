/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:00:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/19 17:50:09 by eala-lah         ###   ########.fr       */
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
		tmp = tmp->nex;
		i++;
	}
}

int	ft_jumpable(t_col **col)
{
	t_col	*tmp;
	int		i;
	int		low;

	tmp = *col;
	i = INT_MAX;
	ft_floor(col);
	low = tmp->pos;
	while (tmp)
	{
		if (tmp->ind < i)
		{
			i = tmp->ind;
			low = tmp->pos;
		}
		tmp = tmp->nex;
	}
	return (low);
}

static int	ft_trampoline(t_col **a, int b_idx, int tgt_idx, int tgt_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->ind > b_idx && tmp_a->ind < tgt_idx)
		{
			tgt_idx = tmp_a->ind;
			tgt_pos = tmp_a->pos;
		}
		tmp_a = TMp_a->nex;
	}
	if (tgt_idx != INT_MAX)
		return (tgt_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->ind < target_idx)
		{
			tgt_idx = tmp_a->ind;
			tgt_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->nex;
	}
	return (tgt_pos);
}

void	ft_push(t_col **a, t_col **b)
{
	t_col	*tmp_b;
	int		tgt_pos;

	tmp_b = *b;
	ft_floor(a);
	ft_floor(b);
	tgt_pos = 0;
	while (tmp_b)
	{
		tgt_pos = ft_trampoline(a, tmp_b->ind, INT_MAX, tgt_pos);
		tmp_b->tgt_pos = tgt_pos;
		tmp_b = tmp_b->nex;
	}
}
