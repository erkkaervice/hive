/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-stacking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/31 13:10:53 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
