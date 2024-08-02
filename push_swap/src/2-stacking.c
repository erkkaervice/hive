/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stacking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/02 16:36:37 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->val = value;
	new->ind = 0;
	new->pos = -1;
	new->tgt = -1;
	new->soa = -1;
	new->sob = -1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_botstack(t_stack *sta)
{
	if (!sta)
		return (NULL);
	while (sta->next)
		sta = sta->next;
	return (sta);
}

t_stack	*ft_2ndbotstack(t_stack *sta)
{
	if (!sta || !sta->next)
		return (NULL);
	while (sta->next->next)
		sta = sta->next;
	return (sta);
}

void	ft_addbotstack(t_stack **sta, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*sta)
	{
		*sta = new;
		return ;
	}
	last = ft_botstack(*sta);
	last->next = new;
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
