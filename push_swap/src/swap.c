/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:06 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/20 13:28:24 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_col *col)
{
	int	tmp;

	if (col == NULL || col->next == NULL)
		return ;
	tmp = col->val;
	col->val = col->next->val;
	col->next->val = tmp;
	tmp = col->ind;
	col->ind = col->next->ind;
	col->next->ind = tmp;
}

void	ft_sa(t_col **col_a)
{
	ft_swap(*col_a);
	ft_putstr("sa\n");
}

void	ft_sb(t_col **col_b)
{
	ft_swap(*col_b);
	ft_putstr("sb\n");
}

void	ft_ss(t_col **col_a, t_col **col_b)
{
	ft_swap(*col_a);
	ft_swap(*col_b);
	ft_putstr("ss\n");
}
