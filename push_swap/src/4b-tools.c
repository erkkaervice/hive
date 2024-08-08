/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4b-tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:08 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/08 17:17:30 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_finder(t_stack *sta)
{
	int	i;

	i = 0;
	while (sta)
	{
		if (sta->ind > i)
			i = sta->ind;
		sta = sta->next;
	}
	return (i);
}

void	ft_dartagnan(t_stack **sta, t_stack **stb)
{
	int	sts;
	int	hit;
	int	i;

	sts = ft_stalen(*sta);
	hit = 0;
	i = 0;
	while (sts > 6 && i < sts && hit < sts / 2)
	{
		if ((*sta)->ind <= sts / 2)
		{
			ft_pb(sta, stb);
			hit++;
		}
		else
			ft_ra(sta);
		i++;
	}
	while (sts - hit > 3)
	{
		ft_pb(sta, stb);
		hit++;
	}
}

void	ft_rearrange(t_stack **sta)
{
	int	low;

	low = ft_lindex(sta);
	if (low >= ft_stalen(*sta) / 2)
		while (low++ < ft_stalen(*sta))
			ft_rra(sta);
	else
		while (low-- > 0)
			ft_ra(sta);
}

void	ft_stepcount(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	tmp = *stb;
	while (tmp)
	{
		if (tmp->pos > ft_stalen(*stb) / 2)
			tmp->sob = (ft_stalen(*stb) - tmp->pos) * -1;
		else
			tmp->sob = tmp->pos;
		if (tmp->tgt > ft_stalen(*sta) / 2)
			tmp->soa = (ft_stalen(*sta) - tmp->tgt) * -1;
		else
			tmp->soa = tmp->tgt;
		tmp = tmp->next;
	}
}

void	ft_quickstep(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		soa;
	int		sob;
	int		qs;
	int		ts;

	tmp = *stb;
	qs = INT_MAX;
	while (tmp)
	{
		ts = ft_abs(tmp->soa) + ft_abs(tmp->sob);
		if (ts < qs)
		{
			qs = ts;
			soa = tmp->soa;
			sob = tmp->sob;
		}
		tmp = tmp->next;
	}
	ft_move(sta, stb, soa, sob);
}
