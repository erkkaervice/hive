/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:41:12 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/25 15:51:06 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*ft_value(int ac, char **av)
{
	t_stack	*sta;
	long	n;
	int		i;

	sta = NULL;
	n = 0;
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n == INT_MAX || n == INT_MIN)
			ft_error(&sta, NULL);
		if (i == 1)
			sta = ft_newstack((int)n);
		else
			ft_addbotstack(&sta, ft_newstack((int)n));
		i++;
	}
	return (sta);
}

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
