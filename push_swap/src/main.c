/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:41:12 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/31 14:55:12 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_swap(t_stack **sta, t_stack **stb, int sts)
{
	if (sts == 2 && !ft_sorted(*sta))
		ft_sa(sta);
	else if (sts == 3)
		ft_short(sta);
	else if (sts > 3 && !ft_sorted(*sta))
		ft_sort(sta, stb);
}

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;

	if (ac < 2)
		return (0);
	if (!ft_valid(av))
		ft_error(NULL, NULL);
	sta = ft_value(ac, av);
	stb = NULL;
	ft_index(sta, ft_stalen(sta) + 1);
	push_swap(&sta, &stb, ft_stalen(sta));
	ft_freee(&sta);
	ft_freee(&stb);
	return (0);
}
