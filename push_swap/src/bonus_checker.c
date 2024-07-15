/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:29:55 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/15 14:00:10 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM(x) ((x) >= '0' && (x) <= '9')

int s_len(t_bonus_stack *stack) 
{
	int len = 0;
	t_bonus_stack *tmp = stack;
	
	while (tmp) 
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int partition(int *stack1, int start, int end) 
{
	int end_value = stack1[end];
	int strt_indx = start - 1;
	int curr_indx = start;

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

void quick_sort(int *stack1, int start, int end) 
{
	int stack2[end + 1];
	int top = -1;
	int pivot;

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

int check_int_overflow(char *str) 
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

int *create_array_from_list(t_bonus_stack *stack, int len) 
{
	int *array = (int*)malloc(sizeof(int) * len);
	int i = 0;

	while (i < len) 
	{
		array[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (array);
}

void stack_del(t_bonus_stack **stack) 
{
	t_bonus_stack *del;
	t_bonus_stack *tmp = *stack;

	while (tmp) 
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

void ft_strdel(char **as) 
{
	if (as == NULL)
		return;
	free(*as);
	*as = NULL;
}

t_bonus_stack *copy_args_in_stack(int argc, char **argv) 
{
	t_bonus_stack *stack = NULL;
	t_bonus_stack *new_node;
	int i = 1;

	while (i < argc) 
	{
		new_node = (t_bonus_stack *)malloc(sizeof(t_bonus_stack));
		if (!new_node)
			return (NULL); // Handle malloc failure
		new_node->val = atoi(argv[i]);
		new_node->next = stack;
		stack = new_node;
		i++;
	}
	return (stack);
}

int check_argv(char *str) 
{
	int i = 0;
	int len;

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

void doubles_checker(t_bonus_stack **stack) 
{
	int *array;
	int len = s_len(*stack);
	int i = 0;

	array = create_array_from_list(*stack, len);
	quick_sort(array, 0, len - 1);

	while (i < len - 1) 
	{
		if (array[i] == array[i + 1]) 
		{
			free(array);
			return;
		}
		i++;
	}
	free(array);
}

t_bonus_stack *create_new_node(void) 
{
	t_bonus_stack *first = (t_bonus_stack*)malloc(sizeof(t_bonus_stack));
	first->num = 0;
	first->next = NULL;
	return (first);
}

int do_commands(char *line, t_bonus_stack **first, t_bonus_stack **second) 
{
	if (ft_strncmp(line, "sa\n", 3) == 0) 
	{
		ft_sa((t_stack **)first);
	} 
	else if (ft_strncmp(line, "sb\n", 3) == 0) 
	{
		ft_sb((t_stack **)second);
	} 
	else if (ft_strncmp(line, "ss\n", 3) == 0) 
	{
		ft_ss((t_stack **)first, (t_stack **)second);
	} 
	else if (ft_strncmp(line, "pa\n", 3) == 0) 
	{
		ft_pa((t_stack **)first, (t_stack **)second);
	} 
	else if (ft_strncmp(line, "pb\n", 3) == 0) 
	{
		ft_pb((t_stack **)second, (t_stack **)first);
	} 
	else if (ft_strncmp(line, "ra\n", 3) == 0) 
	{
		ft_ra((t_stack **)first);
	} 
	else if (ft_strncmp(line, "rb\n", 3) == 0) 
	{
		ft_rb((t_stack **)second);
	} 
	else if (ft_strncmp(line, "rr\n", 3) == 0) 
	{
		ft_rr((t_stack **)first, (t_stack **)second);
	} 
	else if (ft_strncmp(line, "rra\n", 4) == 0) 
	{
		ft_rra((t_stack **)first);
	} 
	else if (ft_strncmp(line, "rrb\n", 4) == 0) 
	{
		ft_rrb((t_stack **)second);
	} 
	else if (ft_strncmp(line, "rrr\n", 4) == 0) 
	{
		ft_rrr((t_stack **)first, (t_stack **)second);
	} 
	else 
	{
		write(2, "Error\n", 6);
		return (1); // Indicate error with non-zero return value
	}
	return (0); // Success
}

int return_errors(char **line, t_bonus_stack **stack1, t_bonus_stack **stack2) 
{
	ft_strdel(line);
	if (*stack1)
		stack_del(stack1);
	if (*stack2)
		stack_del(stack2);
	write(2, "Error\n", 6);
	return (0);
}

int stack_is_sorted(t_bonus_stack *first) 
{
	t_bonus_stack *current = first;

	while (current && current->next) 
	{
		if (current->num > current->next->num) 
		{
			printf("[DEBUG] Stack is not sorted at element %d\n", current->num);
			return 0; // Not sorted
		}
		current = current->next;
	}
	return 1; // Sorted
}

void print_checker_res(t_bonus_stack **first, t_bonus_stack **second) 
{
	if (stack_is_sorted(*first)) 
	{
		if (!(*second)) 
		{
			write(1, "OK\n", 3);
		} 
		else 
		{
			printf("[DEBUG] Stack B is not empty\n");
			write(1, "KO\n", 3);
		}
	} 
	else 
	{
		write(1, "KO\n", 3);
	}
}

int main(int argc, char **argv) 
{
	t_bonus_stack *first;
	t_bonus_stack *second;
	char *line;

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
