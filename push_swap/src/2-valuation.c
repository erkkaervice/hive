/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-valuation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:08 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/30 16:33:34 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *sta)
{
	if (!sta || !sta->next)
		return (1);
	while (sta->next != NULL)
	{
		if (sta->val > sta->next->val)
			return (0);
		sta = sta->next;
	}
	return (1);
}

void	ft_freee(t_stack **sta)
{
	t_stack	*tmp;

	if (!sta || !(*sta))
		return ;
	while (*sta)
	{
		tmp = (*sta)->next;
		free(*sta);
		*sta = tmp;
	}
	*sta = NULL;
}

void	ft_error(t_stack **sta, t_stack **stb)
{
	if (sta == NULL || *sta != NULL)
		ft_freee(sta);
	if (stb == NULL || *stb != NULL)
		ft_freee(stb);
	write(2, "Error\n", 6);
	exit (1);
}

t_stack	*ft_value(int ac, char **av)
{
	t_stack	*sta;
	long	n;
	int		i;

	sta = NULL;
	n = 0;
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n == INT_MAX || n == INT_MIN)
			ft_error(&sta, NULL);
		if (i == 1)
			sta = ft_newstack((int)n);
		else
			ft_addbotstack(&sta, ft_newstack((int)n));
		i++;
	}
	return (sta);
}