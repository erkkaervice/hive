/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:48:59 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/24 16:13:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include "push_swap.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include <unistd.h>

typedef struct s_b_stack
{
	int				val;
	int				ind;
	int				pos;
	int				tgt;
	int				soa;
	int				sob;
	struct s_b_stack	*next;
	int				ft_isdigit;
}					t_b_stack;

void			stack_del(t_b_stack **stack);
void			doubles_checker(t_b_stack **stack);
int				*create_array_from_list(t_b_stack *stack, int len);
int				s_len(t_b_stack *stack);
int				check_int_overflow(char *str);
void			quick_sort(int *sta, int start, int end);
int				check_argv(char *str);
int				do_commands(char *line, t_b_stack **first, t_b_stack **second);
int				return_errors(char **line, t_b_stack **sta, t_b_stack **stb);
int				stack_is_sorted(t_b_stack *first);
void			print_checker_res(t_b_stack **first, t_b_stack **second);
t_b_stack		*create_new_node(void);
t_b_stack		*copy_args_in_stack(int argc, char **argv);
void			ft_strdel(char **as);

#endif
