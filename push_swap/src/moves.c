/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:22 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/26 15:31:52 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_moverrr(t_col **a, t_col **b, int *coa, int *cob)
{
	while (*coa < 0 && *cob < 0)
	{
		(*coa)++;
		(*cob)++;
		ft_rrr(a, b);
	}
}

static void	ft_moverr(t_col **a, t_col **b, int *coa, int *cob)
{
	while (*coa > 0 && *cob > 0)
	{
		(*coa)--;
		(*cob)--;
		ft_rr(a, b);
	}
}

static void	ft_movera(t_col **a, int *stp)
{
	while (*stp)
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

static void	ft_moverb(t_col **b, int *stp)
{
	while (*stp)
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

void	ft_move(t_col **a, t_col **b, int coa, int cob)
{
	if (coa < 0 && cob < 0)
	{
		ft_moverrr(a, b, &coa, &cob);
	}
	else if (coa > 0 && cob > 0)
	{
		ft_moverr(a, b, &coa, &cob);
	}
	ft_movera(a, &coa);
	ft_moverb(b, &cob);
	ft_pa(a, b);
}
