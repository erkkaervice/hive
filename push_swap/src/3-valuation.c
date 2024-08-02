/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-valuation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:08 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/02 16:36:37 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *sta)
{
	while (sta && sta->next)
	{
		if (sta->val > sta->next->val)
			return (0);
		sta = sta->next;
	}
	return (1);
}

int	ft_stalen(t_stack *sta)
{
	int	i;

	i = 0;
	while (sta)
	{
		i++;
		sta = sta->next;
	}
	return (i);
}

