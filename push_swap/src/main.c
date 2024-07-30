/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:41:12 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/30 16:33:36 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **sta, t_stack **stb, int sts)
{
	if (sts == 2 && !ft_sorted(*sta))
		ft_sa(sta);
	else if (sts == 3)
		ft_short(sta);
	else if (sts > 3 && !ft_sorted(*sta))
		ft_sort(sta, stb);
}

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;

	if (ac < 2)
		return (0);
	if (!ft_valid(av))
		ft_error(NULL, NULL);
	sta = ft_value(ac, av);
	stb = NULL;
	ft_index(sta, ft_stalen(sta) + 1);
	push_swap(&sta, &stb, ft_stalen(sta));
	ft_freee(&sta);
	ft_freee(&stb);
	return (0);
}
