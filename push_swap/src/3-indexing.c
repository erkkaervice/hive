/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-indexing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:00:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/08 16:59:57 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_pindex(t_stack **sta)
{
	t_stack	*tmp;
	int		i;

	tmp = *sta;
	i = 0;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}

int	ft_lindex(t_stack **sta)
{
	t_stack	*tmp;
	int		i;
	int		tgtt;

	ft_pindex(sta);
	tmp = *sta;
	i = INT_MAX;
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

static int	ft_sindex(t_stack **sta, int b_ind, int tgt_ind, int tgt_pos)
{
	t_stack	*tmp;

	tmp = *sta;
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
	tmp = *sta;
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

void	ft_tindex(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	ft_pindex(sta);
	ft_pindex(stb);
	tmp = *stb;
	while (tmp)
	{
		tmp->tgt = ft_sindex(sta, tmp->ind, INT_MAX, 0);
		tmp = tmp->next;
	}
}

void	ft_index(t_stack *sta, int sts)
{
	t_stack	*tmp;
	t_stack	*hdx;
	int		num;

	while (--sts > 0)
	{
		tmp = sta;
		num = INT_MIN;
		hdx = NULL;
		while (tmp)
		{
			if (tmp->ind == 0 && tmp->val > num)
			{
				num = tmp->val;
				hdx = tmp;
			}
			tmp = tmp->next;
		}
		if (hdx)
			hdx->ind = sts;
	}
}
