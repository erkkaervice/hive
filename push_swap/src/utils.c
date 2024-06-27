/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:22:32 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/27 12:49:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_free(t_col **col)
{
	t_col	*tmp;

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

void	ft_error(t_col **col_a, t_col **col_b)
{
	if (col_a == NULL || *col_a != NULL)
	{
		ft_free(col_a);
	}
	if (col_b == NULL || *col_b != NULL)
	{
		ft_free(col_b);
	}
	write(2, "Error\n", 6);
	exit (1);
}
