/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:22:32 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/19 17:29:29 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_col **col)
{
	t_col	*tmp;

	if (!col || !(*col))
	{
		return ;
	}
	while (*col)
	{
		tmp = (*col)->nex;
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
