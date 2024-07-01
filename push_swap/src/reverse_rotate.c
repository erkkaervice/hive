/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:14 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 15:44:09 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **col)
{
	t_stack	*tmp;
	t_stack	*end;
	t_stack	*the;

	end = ft_botstack(*col);
	the = ft_2ndbotstack(*col);
	tmp = *col;
	*col = end;
	(*col)->next = tmp;
	the->next = NULL;
}

void	ft_rra(t_stack **sta)
{
	ft_reverse_rotate(sta);
	ft_putstr("rra\n");
}

void	ft_rrb(t_stack **stb)
{
	ft_reverse_rotate(stb);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_stack **sta, t_stack **stb)
{
	ft_reverse_rotate(sta);
	ft_reverse_rotate(stb);
	ft_putstr("rrr\n");
}
