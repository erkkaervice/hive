/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:03 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/25 16:47:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	if (*stb != NULL)
	{
		tmp = *stb;
		*stb = (*stb)->next;
		tmp->next = *sta;
		*sta = tmp;
	}
	ft_putstr("pa\n");
}

void	ft_pb(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	if (*sta != NULL)
	{
		tmp = *sta;
		*sta = (*sta)->next;
		tmp->next = *stb;
		*stb = tmp;
	}
	ft_putstr("pb\n");
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
	int		qs;
	int		soa;
	int		sob;

	tmp = *stb;
	qs = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->soa) + ft_abs(tmp->sob) < ft_abs(qs))
		{
			qs = ft_abs(tmp->sob) + ft_abs(tmp->soa);
			soa = tmp->soa;
			sob = tmp->sob;
		}
		tmp = tmp->next;
	}
	ft_move(sta, stb, soa, sob);
}
