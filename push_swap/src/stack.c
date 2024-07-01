/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 13:44:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_slinky(t_stack *col)
{
	int	i;

	i = 0;
	if (!col)
	{
		return (0);
	}
	while (col)
	{
		col = col->next;
		i++;
	}
	return (i);
}

t_stack	*ft_newstack(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
	{
		return (NULL);
	}
	new->val = value;
	new->ind = 0;
	new->pos = -1;
	new->tgt = -1;
	new->coa = -1;
	new->cob = -1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_botstack(t_stack *col)
{
	while (col && col->next != NULL)
	{
		col = col->next;
	}
	return (col);
}

t_stack	*ft_2ndbotstack(t_stack *col)
{
	while (col && col->next && col->next->next != NULL)
	{
		col = col ->next;
	}
	return (col);
}

void	ft_addbotstack(t_stack **col, t_stack *new)
{
	t_stack	*bar;

	if (!new)
	{
		return ;
	}
	if (!*col)
	{
		*col = new;
		return ;
	}
	bar = ft_botstack(*col);
	bar->next = new;
}
