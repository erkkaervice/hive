/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:03 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/09 15:38:26 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **sta, t_stack **stb)
{
	t_stack *tmp;

	if (*stb)
	{
		tmp = *stb;
		*stb = (*stb)->next;
		tmp->next = *sta;
		*sta = tmp;
	}
	ft_putstr("pa\n");
}

void	ft_pb(t_stack **sta, t_stack **stb)
{
	t_stack *tmp;

	if (*sta)
	{
		tmp = *sta;
		*sta = (*sta)->next;
		tmp->next = *stb;
		*stb = tmp;
	}
	ft_putstr("pb\n");
}
