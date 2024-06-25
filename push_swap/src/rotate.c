/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:05:02 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/25 16:54:18 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_col **col)
{
    t_col *tmp;
    t_col *end;

    if (!*col || !(*col)->next)
        return ;
    tmp = *col;
    *col = (*col)->next;
    end = *col;
    while (end->next != NULL)
        end = end->next;
    end->next = tmp;
    tmp->next = NULL;
}


void	ft_ra(t_col **col_a)
{
	ft_rotate(col_a);
	ft_putstr("ra\n");
}

void	ft_rb(t_col **col_b)
{
	ft_rotate(col_b);
	ft_putstr("rb\n");
}

void	ft_rr(t_col **col_a, t_col **col_b)
{
	ft_rotate(col_a);
	ft_rotate(col_b);
	ft_putstr("rr\n");
}
