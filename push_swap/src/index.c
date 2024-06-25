/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:57:36 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/25 15:53:56 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_col	*ft_value(int ac, char **av)
{
	t_col		*col_a;
	long int	n;
	int		i;

	col_a = NULL;
	n = 0;
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_error(&col_a, NULL);
		}
		if (i == 1)
		{
			col_a = ft_wtc7((int)n);
		}
		else
		{
			ft_lobbybar(&col_a, ft_wtc7((int)n));
		}
		i++;
	}
	return (col_a);
}

void	ft_index(t_col *col_a, int cos)
{
	t_col *ptr;
	t_col *sdd;
	int	min;

	while (--cos  > 0)
	{
		ptr = col_a;
		min = INT_MIN;
		sdd = NULL;
		while (ptr)
		{
			if (ptr->val == INT_MIN && ptr->ind == 0)
				ptr->ind = 1;
			if (ptr->val > min && ptr->ind == 0)
			{
				min = ptr->val;
				sdd = ptr;
				ptr = col_a;
			}
			else
				ptr =  ptr->next;
		}
		if (sdd != NULL)
			sdd->ind = cos;
	}
}
