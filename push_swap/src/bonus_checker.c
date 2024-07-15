/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:29:55 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/15 16:36:59 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	s_len(t_b_stack *stack)
{
	int			len;
	t_b_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

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
			ft_swap(&sta[strt_indx], &sta[curr_indx]);
			strt_indx++;
		}
		curr_indx++;
	}
	ft_swap(&sta[strt_indx + 1], &sta[end]);
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

int	check_int_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	else
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int	*create_array_from_list(t_b_stack *stack, int len)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = stack->ft_isdigit;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	stack_del(t_b_stack **stack)
{
	t_b_stack	*del;
	t_b_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

t_b_stack	*copy_args_in_stack(int argc, char **argv)
{
	t_b_stack	*stack;
	t_b_stack	*new_node;
	int			i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = (t_b_stack *)malloc(sizeof(t_b_stack));
		if (!new_node)
			return (NULL);
		new_node->val = atoi(argv[i]);
		new_node->next = stack;
		stack = new_node;
		i++;
	}
	return (stack);
}

int	check_argv(char *str)
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
	if (len == 10 && check_int_overflow(str))
		return (1);
	return (0);
}

void	doubles_checker(t_b_stack **stack)
{
	int	*array;
	int	len;
	int	i;

	len = s_len(*stack);
	array = create_array_from_list(*stack, len);
	if (array == NULL)
		return ;
	quick_sort(array, 0, len - 1);
	i = 0;
	while (i < len - 1)
	{
		if (array[i] == array[i + 1])
		{
			free(array);
			return ;
		}
		i++;
	}
	free(array);
}

int	do_commands(char *line, t_b_stack **first, t_b_stack **second)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_sa((t_stack **)first);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_sb((t_stack **)second);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss((t_stack **)first, (t_stack **)second);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_pa((t_stack **)first, (t_stack **)second);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_pb((t_stack **)second, (t_stack **)first);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_ra((t_stack **)first);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rb((t_stack **)second);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr((t_stack **)first, (t_stack **)second);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_rra((t_stack **)first);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_rrb((t_stack **)second);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_rrr((t_stack **)first, (t_stack **)second);
	else
		return (write(2, "Error\n", 6), 1);
	return (0);
}

int	return_errors(char **line, t_b_stack **sta, t_b_stack **stb)
{
	ft_strdel(line);
	if (*sta)
		stack_del(sta);
	if (*stb)
		stack_del(stb);
	write(2, "Error\n", 6);
	return (0);
}

int	stack_is_sorted(t_b_stack *first)
{
	t_b_stack	*current;

	current = first;
	while (current && current->next)
	{
		if (current->ft_isdigit > current->next->ft_isdigit)
			return (0);
		current = current->next;
	}
	return (1);
}

void	print_checker_res(t_b_stack **first, t_b_stack **second)
{
	if (stack_is_sorted(*first))
	{
		if (!(*second))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_b_stack	*first;
	t_b_stack	*second;
	char		*line;

	if (argc < 2)
		return (0);
	if (!(first = copy_args_in_stack(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	second = NULL;
	while ((line = get_next_line(0)) != NULL)
	{
		if (do_commands(line, &first, &second))
			return (return_errors(&line, &first, &second));
		ft_strdel(&line);
	}
	print_checker_res(&first, &second);
	return (0);
}
