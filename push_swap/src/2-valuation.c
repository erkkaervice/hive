/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-valuation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:08 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/02 13:23:04 by eala-lah         ###   ########.fr       */
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

t_stack	*ft_value(int ac, char **av)
{
	t_stack	*sta;
	long	n;
	int		i;

	sta = NULL;
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error(&sta, NULL);
		ft_addbotstack(&sta, ft_newstack((int)n));
		i++;
	}
	return (sta);
}
