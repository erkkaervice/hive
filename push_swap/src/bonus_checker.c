/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:29:55 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/24 16:13:11 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
		new_node->val = ft_atoi(argv[i]);
		new_node->next = stack;
		stack = new_node;
		i++;
	}
	return (stack);
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

void	ft_result(t_b_stack **first, t_b_stack **second)
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
	ft_result(&first, &second);
	return (0);
}
