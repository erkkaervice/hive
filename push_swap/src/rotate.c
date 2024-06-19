/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:05:02 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/19 15:27:41 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_col **col)
{
	t_col	*tmp;
	t_col	end;

	tmp = *col;
	*col = (*col)->nex;
	end = ft_lobby(*col);
	tmp->nex = NULL;
	end->nex = tmp;
}

void	ft_ra(t_col **col_a)
{
	ft_rotate(col_a);
	ft_putstr("ra\n");
}

void	ft_rb(t_col **col_b)
{
	ft_rotate(col_b);
	ft_putstr("ra\n");
}

void	ft_rr(t_col **col_a, t_col **col_b)
{
	ft_rotate(col_a);
	ft_rotate(col_b);
	ft_putstr("rr\n");
}
