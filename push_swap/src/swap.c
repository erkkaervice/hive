/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:06 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/31 13:09:20 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **sta)
{
	t_stack	*tmp;

	if (!sta || !*sta || !(*sta)->next)
		return ;
	tmp = (*sta)->next;
	(*sta)->next = tmp->next;
	tmp->next = *sta;
	*sta = tmp;
}

void	ft_sa(t_stack **sta)
{
	ft_swap(sta);
	ft_putstr("sa\n");
}

void	ft_sb(t_stack **stb)
{
	ft_swap(stb);
	ft_putstr("sb\n");
}

void	ft_ss(t_stack **sta, t_stack **stb)
{
	ft_swap(sta);
	ft_swap(stb);
	ft_putstr("ss\n");
}
