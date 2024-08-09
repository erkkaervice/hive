/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-moving.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:22 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/09 15:14:59 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_both(t_stack **a, t_stack **b, int *soa, int *sob)
{
	if (*soa < 0 && *sob < 0)
	{
		while (*soa < 0 && *sob < 0)
		{
			(*soa)++;
			(*sob)++;
			ft_rrr(a, b);
		}
	}
	else if (*soa > 0 && *sob > 0)
	{
		while (*soa > 0 && *sob > 0)
		{
			(*soa)--;
			(*sob)--;
			ft_rr(a, b);
		}
	}
}

static void	ft_one(t_stack **a, t_stack **b, int *soa, int *sob)
{
	while (*soa != 0)
	{
		if (*soa > 0)
		{
			ft_ra(a);
			(*soa)--;
		}
		else
		{
			ft_rra(a);
			(*soa)++;
		}
	}

	while (*sob != 0)
	{
		if (*sob > 0)
		{
			ft_rb(b);
			(*sob)--;
		}
		else
		{
			ft_rrb(b);
			(*sob)++;
		}
	}
}

void	ft_move(t_stack **a, t_stack **b, int soa, int sob)
{
	ft_both(a, b, &soa, &sob);
	ft_one(a, b, &soa, &sob);
	ft_pa(a, b);
}
