/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:42:48 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 15:49:42 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stepcount(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		soa;
	int		sob;

	tmp_a = *sta;
	tmp_b = *stb;
	soa = ft_slinky(tmp_a);
	sob = ft_slinky(tmp_b);
	while (tmp_b)
	{
		tmp_b->cob = tmp_b->pos;
		if (tmp_b->pos > sob / 2)
		{
			tmp_b->cob = (sob - tmp_b->pos) * -1;
		}
		tmp_b->coa = tmp_b->tgt;
		if (tmp_b->tgt > soa / 2)
		{
			tmp_b->coa = (soa - tmp_b->tgt) * -1;
		}
		tmp_b = tmp_b->next;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	return (n);
}

void	ft_quickstep(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		qs;
	int		coa;
	int		cob;

	tmp = *stb;
	qs = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->coa) + ft_abs(tmp->cob) < ft_abs(qs))
		{
			qs = ft_abs(tmp->cob) + ft_abs(tmp->coa);
			coa = tmp->coa;
			cob = tmp->cob;
		}
		tmp = tmp->next;
	}
	ft_move(sta, stb, coa, cob);
}
