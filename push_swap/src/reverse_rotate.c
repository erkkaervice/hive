/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:14 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/20 13:28:24 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_col **col)
{
	t_col	*tmp;
	t_col	*end;
	t_col	*the;

	end = ft_lobby(*col);
	the = ft_stairs(*col);
	tmp = *col;
	*col = end;
	(*col)->next = tmp;
	the->next = NULL;
}

void	ft_rra(t_col **col_a)
{
	ft_reverse_rotate(col_a);
	ft_putstr("rra\n");
}

void	ft_rrb(t_col **col_b)
{
	ft_reverse_rotate(col_b);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_col **col_a, t_col **col_b)
{
	ft_reverse_rotate(col_a);
	ft_reverse_rotate(col_b);
	ft_putstr("rrr\n");
}
