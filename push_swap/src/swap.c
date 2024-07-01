/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:06 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 15:33:45 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *col)
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

void	ft_sa(t_stack **sta)
{
	ft_swap(*sta);
	ft_putstr("sa\n");
}

void	ft_sb(t_stack **stb)
{
	ft_swap(*stb);
	ft_putstr("sb\n");
}

void	ft_ss(t_stack **sta, t_stack **stb)
{
	ft_swap(*sta);
	ft_swap(*stb);
	ft_putstr("ss\n");
}
