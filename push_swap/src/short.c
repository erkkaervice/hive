/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:50 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/02 19:19:39 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_finder(t_stack *sta)
{
	int	i;

	i = sta->ind;
	while (sta)
	{
		if (sta->ind > i)
		{
			i = sta->ind;
		}
		sta = sta->next;
	}
	return (i);
}

void	ft_short(t_stack **sta)
{
	int	i;

	if (ft_sorted(*sta))
		return ;
	i = ft_finder(*sta);
	if ((*sta)->ind == i)
		ft_ra(sta);
	else if ((*sta)->next->ind == i)
		ft_rra(sta);
	if ((*sta)->ind > (*sta)->next->ind)
		ft_sa(sta);
}
