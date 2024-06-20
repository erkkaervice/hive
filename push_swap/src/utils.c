/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:22:32 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/20 13:28:24 by eala-lah         ###   ########.fr       */
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

int	ft_psscmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
		{
			i++;
		}
	}
	else
	{
		if (s2[j] == '+')
		{
			j++;
		}
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
