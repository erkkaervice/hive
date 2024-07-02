/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:22:44 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/02 19:15:09 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_dartagnan(t_stack **sta, t_stack **stb)
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

static void	ft_rearrange(t_stack **sta)
{
	int	res;

	res = ft_lindex(sta);
	if (res > ft_stalen(*sta) / 2)
	{
		while (res < ft_stalen(*sta))
		{
			ft_rra(sta);
			res++;
		}
	}
	else
	{
		while (res > 0)
		{
			ft_ra(sta);
			res--;
		}
	}
}

void	ft_sort(t_stack **sta, t_stack **stb)
{
	ft_dartagnan(sta, stb);
	ft_short(sta);
	while (*stb)
	{
		ft_tindex(sta, stb);
		ft_stepcount(sta, stb);
		ft_quickstep(sta, stb);
	}
	if (!ft_sorted(*sta))
		ft_rearrange(sta);
}
