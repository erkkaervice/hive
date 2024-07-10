/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:00:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/10 17:03:32 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_findex(t_stack **sta)
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

	tmp = *sta;
	i = INT_MAX;
	ft_findex(sta);
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
		tmp->tgt = ft_sindex(a, tmp->ind, INT_MAX, tgt_pos);
		tmp = tmp->next;
	}
}

void	ft_index(t_stack *sta, int sts)
{
	t_stack	*ptr;
	t_stack	*hdx;
	int		min;

	while (--sts > 0)
	{
		ptr = sta;
		min = INT_MIN;
		hdx = NULL;
		while (ptr)
		{
			if (ptr->val == INT_MIN && ptr->ind == 0)
				ptr->ind = 1;
			if (ptr->val > min && ptr->ind == 0)
			{
				min = ptr->val;
				hdx = ptr;
				ptr = sta;
			}
			else
				ptr = ptr->next;
		}
		if (hdx != NULL)
			hdx->ind = sts;
	}
}
