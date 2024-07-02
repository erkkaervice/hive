/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:05:02 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/02 19:00:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **sta)
{
	t_stack	*tmp;
	t_stack	*end;

	tmp = *sta;
	*sta = (*sta)->next;
	end = ft_botstack(*sta);
	tmp->next = NULL;
	end->next = tmp;
}

void	ft_ra(t_stack **sta)
{
	ft_rotate(sta);
	ft_putstr("ra\n");
}

void	ft_rb(t_stack **stb)
{
	ft_rotate(stb);
	ft_putstr("rb\n");
}

void	ft_rr(t_stack **sta, t_stack **stb)
{
	ft_rotate(sta);
	ft_rotate(stb);
	ft_putstr("rr\n");
}
