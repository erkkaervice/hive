/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:48:59 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/12 11:44:11 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include "push_swap.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include <unistd.h>

typedef struct	s_bonus_stack
{
	int				val;
	int				ind;
	int				pos;
	int				tgt;
	int				soa;
	int				sob;
	struct s_bonus_stack	*next;
	int					num;
	int					diff;
}						t_bonus_stack;

void			stack_del(t_bonus_stack **stack);
void			doubles_checker(t_bonus_stack **stack);
int				*create_array_from_list(t_bonus_stack *stack, int len);
int				s_len(t_bonus_stack *stack);
int				check_int_overflow(char *str);
void			quick_sort(int *stack1, int start, int end);
int				check_argv(char *str);
int				do_commands(char *line, t_bonus_stack **first, t_bonus_stack **second);
int				return_errors(char **line, t_bonus_stack **stack1, t_bonus_stack **stack2);
int				stack_is_sorted(t_bonus_stack *first);
void			print_checker_res(t_bonus_stack **first, t_bonus_stack **second);
t_bonus_stack	*create_new_node(void);
t_bonus_stack	*copy_args_in_stack(int argc, char **argv);
void			ft_strdel(char **as);

#endif
