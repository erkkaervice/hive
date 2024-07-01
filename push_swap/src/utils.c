/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:22:32 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 15:53:29 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_free(t_stack **col)
{
	t_stack	*tmp;

	if (!col || !(*col))
	{
		return ;
	}
	while (*col)
	{
		tmp = (*col)->next;
		free(*col);
		*col = tmp;
	}
	*col = NULL;
}

void	ft_error(t_stack **sta, t_stack **stb)
{
	if (sta == NULL || *sta != NULL)
	{
		ft_free(sta);
	}
	if (stb == NULL || *stb != NULL)
	{
		ft_free(stb);
	}
	write(2, "Error\n", 6);
	exit (1);
}
