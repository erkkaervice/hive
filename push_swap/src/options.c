/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:00:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 13:35:39 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_findex(t_stack **col)
{
	t_stack	*tmp;
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

int	ft_lindex(t_stack **col)
{
	t_stack	*tmp;
	int		i;
	int		tgtt;

	tmp = *col;
	i = INT_MAX;
	ft_findex(col);
	tgtt = tmp->pos;
	while (tmp)
	{
		if (tmp->ind < i)
		{
			i = tmp->ind;
			tgtt = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tgtt);
}

static int	ft_sindex(t_stack **a, int b_ind, int tgt_ind, int tgt_pos)
{
	t_stack	*tmp;

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

void	ft_tindex(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		tgt_pos;

	tmp = *b;
	ft_findex(a);
	ft_findex(b);
	tgt_pos = 0;
	while (tmp)
	{
		tgt_pos = ft_sindex(a, tmp->ind, INT_MAX, tgt_pos);
		tmp->tgt = tgt_pos;
		tmp = tmp->next;
	}
}
