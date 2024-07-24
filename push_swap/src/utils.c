/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:22:32 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/24 16:05:30 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *sta)
{
	if (!sta || !sta->next)
		return (1);
	while (sta->next != NULL)
	{
		if (sta->val > sta->next->val)
			return (0);
		sta = sta->next;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_freee(t_stack **sta)
{
	t_stack	*tmp;

	if (!sta || !(*sta))
		return ;
	while (*sta)
	{
		tmp = (*sta)->next;
		free(*sta);
		*sta = tmp;
	}
	*sta = NULL;
}

void	ft_error(t_stack **sta, t_stack **stb)
{
	if (sta == NULL || *sta != NULL)
		ft_freee(sta);
	if (stb == NULL || *stb != NULL)
		ft_freee(stb);
	write(2, "Error\n", 6);
	exit (1);
}
