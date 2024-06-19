/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:41:12 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/19 17:29:57 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_col *col)
{
	while (col->nex != NULL)
	{
		if (col->val > col->nex->val)
		{
			return (0);
		}
		col = col->nex;
	}
	return (1);
}

static void	push_swap(t_col **col_a, t_col **col_b, int cos)
{
	if (cos == 2 && !ft_sorted(*col_a))
	{
		ft_sa(col_a);
	}
	else if (cos == 3)
	{
		ft_short(col_a);
	}
	else if (cos > 3 && !ft_sorted(*col_a))
	{
		ft_sort(col_a, col_b);
	}
}

int	main(int ac, char **av)
{
	t_col	*col_a;
	t_col	*col_b;
	int		cos;

	if (ac < 2)
	{
		return (NULL);
	}
	if (!CHECKER FOR CORRECT INPUT(av))
	{
		ft_error(NULL, NULL);
	}
	col_a = FILL WITH VALUE(ac, av);
	col_b = NULL;
	cos = ft_slinky(col_a);
	ft_ASSIGN INDEX(col_a, cos + 1);
	push_swap(&col_a, &col_b, cos);
	ft_free(col_a);
	ft_free(col_b);
	return (0);
}
