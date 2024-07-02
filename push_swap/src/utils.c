/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:22:32 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/02 18:43:19 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);	
}

void	ft_free(t_stack **sta)
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
		ft_free(sta);
	if (stb == NULL || *stb != NULL)
		ft_free(stb);
	write(2, "Error\n", 6);
	exit (1);
}
