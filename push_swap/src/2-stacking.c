/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/02 19:38:53 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stalen(t_stack *sta)
{
	int	i;

	i = 0;
	while (sta != NULL)
	{
		sta = sta->next;
		i++;
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
	while (sta && sta->next != NULL)
		sta = sta->next;
	return (sta);
}

t_stack	*ft_2ndbotstack(t_stack *sta)
{
	while (sta && sta->next && sta->next->next != NULL)
		sta = sta ->next;
	return (sta);
}

void	ft_addbotstack(t_stack **sta, t_stack *new)
{
	if (!new)
		return ;
	if (!*sta)
	{
		*sta = new;
		return ;
	}
	ft_botstack(*sta)->next = new;
}
