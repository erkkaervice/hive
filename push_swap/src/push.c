/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:03 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/19 15:06:09 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_col **src, t_col **dst)
{
	t_col	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->nex;
	(*src)->nex = *dst;
	*dst = *src;
	*src = tmp;
}

void	ft_pa(t_col **col_a, t_col **col_b)
{
	ft_push(col_a, col_b);
	ft_putstr("pa\n");
}

void	ft_pb(t_col **col_a, t_col **col_b)
{
	ft_push(col_a, col_b);
	ft_putstr("pb\n");
}
