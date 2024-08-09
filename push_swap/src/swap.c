/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:06 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/09 16:03:48 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **sta)
{
	t_stack *first;
	t_stack *second;

	if (*sta && (*sta)->next)
	{
		first = *sta;
		second = (*sta)->next;
		first->next = second->next;
		second->next = first;
		*sta = second;
	}
	ft_putstr("sa\n");
}

void	ft_sb(t_stack **stb)
{
	t_stack *first;
	t_stack *second;

	if (*stb && (*stb)->next)
	{
		first = *stb;
		second = (*stb)->next;
		first->next = second->next;
		second->next = first;
		*stb = second;
	}
	ft_putstr("sb\n");
}

void	ft_ss(t_stack **sta, t_stack **stb)
{
	ft_sa(sta);
	ft_sb(stb);
	ft_putstr("ss\n");
}
