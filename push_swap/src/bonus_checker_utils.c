/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:50:39 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/25 15:26:35 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	partition(int *sta, int start, int end)
{
	int	end_value;
	int	strt_indx;
	int	curr_indx;

	end_value = sta[end];
	strt_indx = start - 1;
	curr_indx = start;
	while (curr_indx <= end - 1)
	{
		if (sta[curr_indx] <= end_value)
		{
			ft_monte(&sta[strt_indx], &sta[curr_indx]);
			strt_indx++;
		}
		curr_indx++;
	}
	ft_monte(&sta[strt_indx + 1], &sta[end]);
	return (strt_indx + 1);
}

void	quick_sort(int *sta, int start, int end)
{
	int	*stb;
	int	top;
	int	pivot;

	stb = (int *)malloc(sizeof(int) * (end + 1));
	if (!stb)
		return ;
	top = -1;
	stb[++top] = start;
	stb[++top] = end;
	while (top >= 0)
	{
		end = stb[top--];
		start = stb[top--];
		pivot = partition(sta, start, end);
		if (pivot - 1 > start)
		{
			stb[++top] = start;
			stb[++top] = pivot - 1;
		}
		if (pivot + 1 < end)
		{
			stb[++top] = pivot + 1;
			stb[++top] = end;
		}
	}
	free(stb);
}

int	*create_array_from_list(t_stack *stack, int len)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = stack->val;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	stack_del(t_stack **stack)
{
	t_stack	*del;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

int	check_av(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '-' && !ft_isdigit(str[i + 1]))
		return (1);
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (len == 10 && ft_atoi(str) != 0)
		return (1);
	return (0);
}
