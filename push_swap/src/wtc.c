/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/25 17:01:47 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_col	*ft_lobby(t_col *col)
{
	while (col && col->next != NULL)
	{
		col = col->next;
	}
	return (col);
}

t_col	*ft_stairs(t_col *col)
{
	while (col && col->next && col->next->next != NULL)
	{
		col = col ->next;
	}
	return (col);
}

int	ft_slinky(t_col *col)
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

t_col	*ft_wtc7(int value)
{
	t_col	*new;

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

void	ft_lobbybar(t_col **col, t_col *new)
{
	t_col *bar;

	if (!new)
	{
		return ;
	}
	if (!*col)
	{
		*col = new;
		return ;
	}
	bar = ft_lobby(*col);
	bar->next = new;
}
