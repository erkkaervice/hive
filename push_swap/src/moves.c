/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:22 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/02 19:38:53 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_moverrr(t_stack **a, t_stack **b, int *soa, int *sob)
{
	while (*soa < 0 && *sob < 0)
	{
		(*soa)++;
		(*sob)++;
		ft_rrr(a, b);
	}
}

static void	ft_moverr(t_stack **a, t_stack **b, int *soa, int *sob)
{
	while (*soa > 0 && *sob > 0)
	{
		(*soa)--;
		(*sob)--;
		ft_rr(a, b);
	}
}

static void	ft_movera(t_stack **a, int *stp)
{
	while (*stp != 0)
	{
		if (*stp > 0)
		{
			ft_ra(a);
			(*stp)--;
		}
		else if (*stp < 0)
		{
			ft_rra(a);
			(*stp)++;
		}
	}
}

static void	ft_moverb(t_stack **b, int *stp)
{
	while (*stp != 0)
	{
		if (*stp > 0)
		{
			ft_rb(b);
			(*stp)--;
		}
		else if (*stp < 0)
		{
			ft_rrb(b);
			(*stp)++;
		}
	}
}

void	ft_move(t_stack **a, t_stack **b, int soa, int sob)
{
	if (soa < 0 && sob < 0)
		ft_moverrr(a, b, &soa, &sob);
	else if (soa > 0 && sob > 0)
		ft_moverr(a, b, &soa, &sob);
	ft_movera(a, &soa);
	ft_moverb(b, &sob);
	ft_pa(a, b);
}
