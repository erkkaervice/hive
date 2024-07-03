/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:42:48 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 12:07:55 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (n > INT_MAX || n < INT_MIN)
			ft_error(&sta, NULL);
		if (i == 1)
			sta = ft_newstack((int)n);
		else
			ft_addbotstack(&sta, ft_newstack((int)n));
		i++;
	}
	return (sta);
}

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

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_quickstep(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		qs;
	int		soa;
	int		sob;

	tmp = *stb;
	qs = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->soa) + ft_abs(tmp->sob) < ft_abs(qs))
		{
			qs = ft_abs(tmp->sob) + ft_abs(tmp->soa);
			soa = tmp->soa;
			sob = tmp->sob;
		}
		tmp = tmp->next;
	}
	ft_move(sta, stb, soa, sob);
}
