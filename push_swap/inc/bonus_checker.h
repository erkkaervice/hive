/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:48:59 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/24 17:07:27 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include "push_swap.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include <unistd.h>

void			stack_del(t_stack **stack);
int				*create_array_from_list(t_stack *stack, int len);
void			quick_sort(int *sta, int start, int end);
int				check_argv(char *str);
int				do_commands(char *line, t_stack **first, t_stack **second);
int				return_errors(char **line, t_stack **sta, t_stack **stb);
int				stack_is_sorted(t_stack *first);
t_stack			*create_new_node(void);
t_stack			*copy_args_in_stack(int argc, char **argv);
void			ft_strdel(char **as);

#endif
