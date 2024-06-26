/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:41:12 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 16:12:40 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *col)
{
	while (col->next != NULL)
	{
		if (col->val > col->next->val)
		{
			return (0);
		}
		col = col->next;
	}
	return (1);
}

static void	push_swap(t_stack **sta, t_stack **stb, int sts)
{
	if (sts == 2 && !ft_sorted(*sta))
	{
		ft_sa(sta);
	}
	else if (sts == 3)
	{
		ft_short(sta);
	}
	else if (sts > 3 && !ft_sorted(*sta))
	{
		ft_sort(sta, stb);
	}
}

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;

	if (ac < 2)
	{
		return (0);
	}
	if (!ft_valid(av))
	{
		ft_error(NULL, NULL);
	}
	stb = NULL;
	sta = ft_value(ac, av);
	ft_index(sta, ft_slinky(sta) + 1);
	push_swap(&sta, &stb, ft_slinky(sta));
	ft_free(&sta);
	ft_free(&stb);
	return (0);
}
