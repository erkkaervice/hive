/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:50:02 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/11 17:30:17 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"
#include <stdio.h>

#define NUM(x) ((x) >= '0' && (x) <= '9')

int		s_len(t_bonus_stack *stack)
{
	int		len;
	t_bonus_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(int *stack1, int start, int end)
{
	int	end_value;
	int	strt_indx;
	int	curr_indx;

	end_value = stack1[end];
	strt_indx = start - 1;
	curr_indx = start;
	while (curr_indx <= end - 1)
	{
		if (stack1[curr_indx] <= end_value)
		{
			strt_indx++;
			ft_swap(&stack1[strt_indx], &stack1[curr_indx]);
		}
		curr_indx++;
	}
	ft_swap(&stack1[strt_indx + 1], &stack1[end]);
	return (strt_indx + 1);
}

void	quick_sort(int *stack1, int start, int end)
{
	int	stack2[end + 1];
	int	top;
	int	pivot;

	top = -1;
	stack2[++top] = start;
	stack2[++top] = end;
	while (top >= 0)
	{
		end = stack2[top--];
		start = stack2[top--];
		pivot = partition(stack1, start, end);
		if (pivot - 1 > start)
		{
			stack2[++top] = start;
			stack2[++top] = pivot - 1;
		}
		if (pivot + 1 < end)
		{
			stack2[++top] = pivot + 1;
			stack2[++top] = end;
		}
	}
}

int		check_int_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int		*create_array_from_list(t_bonus_stack *stack, int len)
{
	int		*array;
	int		i;

	array = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		array[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	stack_del(t_bonus_stack **stack)
{
	t_bonus_stack	*del;
	t_bonus_stack	*tmp;

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

int		do_commands(char *line, t_bonus_stack **first, t_bonus_stack **second)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
	{
		printf("[DEBUG] Executing sa command\n");
		ft_sa((t_stack **)first);
	}
	else if (ft_strncmp(line, "sb\n", 3) == 0)
	{
		printf("[DEBUG] Executing sb command\n");
		ft_sb((t_stack **)second);
	}
	else if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		printf("[DEBUG] Executing ss command\n");
		ft_ss((t_stack **)first, (t_stack **)second);
	}
	else if (ft_strncmp(line, "pa\n", 3) == 0)
	{
		printf("[DEBUG] Executing pa command\n");
		ft_pa((t_stack **)first, (t_stack **)second);
	}
	else if (ft_strncmp(line, "pb\n", 3) == 0)
	{
		printf("[DEBUG] Executing pb command\n");
		ft_pb((t_stack **)second, (t_stack **)first);
	}
	else if (ft_strncmp(line, "ra\n", 3) == 0)
	{
		printf("[DEBUG] Executing ra command\n");
		ft_ra((t_stack **)first);
	}
	else if (ft_strncmp(line, "rb\n", 3) == 0)
	{
		printf("[DEBUG] Executing rb command\n");
		ft_rb((t_stack **)second);
	}
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		printf("[DEBUG] Executing rr command\n");
		ft_rr((t_stack **)first, (t_stack **)second);
	}
	else if (ft_strncmp(line, "rra\n", 4) == 0)
	{
		printf("[DEBUG] Executing rra command\n");
		ft_rra((t_stack **)first);
	}
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
	{
		printf("[DEBUG] Executing rrb command\n");
		ft_rrb((t_stack **)second);
	}
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		printf("[DEBUG] Executing rrr command\n");
		ft_rrr((t_stack **)first, (t_stack **)second);
	}
	else
	{
		printf("[DEBUG] Unrecognized command: \"%s\"\n", line);
		write(2, "Error\n", 6);
		return (1); // Indicate error with non-zero return value
	}
	return (0); // Success
}


int		return_errors(char **line, t_bonus_stack **stack1, t_bonus_stack **stack2)
{
	ft_strdel(line);
	if (*stack1)
		stack_del(stack1);
	if (*stack2)
		stack_del(stack2);
	write(2, "Error\n", 6);
	return (0); // Assuming 0 means success, adjust as needed
}

int		stack_is_sorted(t_bonus_stack *first)
{
	t_bonus_stack *stack;

	stack = first;
	while (stack->next)
	{
		if (stack->num >= stack->next->num)
			return (1); // Adjust this condition based on your sorting criteria
		stack = stack->next;
	}
	return (0); // Assuming 0 means sorted, adjust as needed
}

void	print_checker_res(t_bonus_stack **first, t_bonus_stack **second)
{
	ft_printf("Entering print_checker_res\n"); // Debug print
	if (!(stack_is_sorted(*first)) && !(*second))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (*first)
		stack_del(first);
	if (*second)
		stack_del(second);
	ft_printf("Exiting print_checker_res\n"); // Debug print
}

t_bonus_stack	*copy_args_in_stack(int argc, char **argv)
{
	int		i;
	t_bonus_stack	*first;
	t_bonus_stack	*tmp;

	ft_printf("Copying arguments into stack\n"); // Debug print
	i = 1;
	first = create_new_node();
	tmp = first;
	while (i < argc)
	{
		if (check_argv(argv[i]))
		{
			stack_del(&first);
			return (NULL);
		}
		tmp->num = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		i++;
	}
	doubles_checker(&first);
	ft_printf("Finished copying arguments into stack\n"); // Debug print
	return (first);
}

int		check_argv(char *str)
{
	int		i;
	int		len;

	i = 0;
	if (str[i] == '-' && !NUM(str[i + 1]))
		return (1);
	if (str[i] == '-' && NUM(str[i + 1]))
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10)
		return (1);
	while (str[i])
	{
		if (!NUM(str[i]))
			return (1);
		i++;
	}
	if (len == 10 && check_int_overflow(str))
		return (1);
	return (0);
}

void	doubles_checker(t_bonus_stack **stack)
{
	int		*array;
	int		len;
	int		i;

	ft_printf("Checking for duplicates\n"); // Debug print
	i = 0;
	len = s_len(*stack);
	array = create_array_from_list(*stack, len);
	quick_sort(array, 0, len - 1);
	while (i < len - 1)
	{
		if (array[i] >= array[i + 1])
		{
			stack_del(stack);
			free(array);
			ft_printf("Duplicate found\n"); // Debug print
			return ;
		}
		i++;
	}
	free(array);
	ft_printf("No duplicates found\n"); // Debug print
}

t_bonus_stack	*create_new_node(void)
{
	t_bonus_stack	*first;

	first = (t_bonus_stack*)malloc(sizeof(t_bonus_stack));
	first->num = 0;
	first->next = NULL;
	return (first);
}

int		main(int argc, char **argv)
{
	t_bonus_stack *first;
	t_bonus_stack *second;
	char	*line;

	ft_printf("Starting main function\n"); // Debug print
	if (argc < 2)
		return (0);
	if (!(first = copy_args_in_stack(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	second = NULL;
	ft_printf("Entering command loop\n"); // Debug print
	while ((line = get_next_line(0)))
	{
		ft_printf("Read line: %s\n", line); // Debug print
		if (do_commands(line, &first, &second))
		{
			ft_strdel(&line);
			return (return_errors(&line, &first, &second));
		}
		ft_strdel(&line);
	}
	ft_printf("Finished reading commands\n"); // Debug print
	print_checker_res(&first, &second);
	return (0);
}
