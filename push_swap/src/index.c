/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:57:36 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 15:39:26 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_error(&sta, NULL);
		}
		if (i == 1)
		{
			sta = ft_newstack((int)n);
		}
		else
		{
			ft_addbotstack(&sta, ft_newstack((int)n));
		}
		i++;
	}
	return (sta);
}

void	ft_index(t_stack *sta, int sts)
{
	t_stack	*ptr;
	t_stack	*hdx;
	int		min;

	while (--sts > 0)
	{
		ptr = sta;
		min = INT_MIN;
		hdx = NULL;
		while (ptr)
		{
			if (ptr->val == INT_MIN && ptr->ind == 0)
				ptr->ind = 1;
			if (ptr->val > min && ptr->ind == 0)
			{
				min = ptr->val;
				hdx = ptr;
				ptr = sta;
			}
			else
				ptr = ptr->next;
		}
		if (hdx != NULL)
			hdx->ind = sts;
	}
}
