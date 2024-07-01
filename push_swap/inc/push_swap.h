/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:27 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/01 15:33:45 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				val;
	int				ind;
	int				pos;
	int				tgt;
	int				coa;
	int				cob;
	struct s_stack	*next;
}	t_stack;

//index
t_stack		*ft_value(int ac, char **av);
void		ft_index(t_stack *sta, int sts);

//main
int			main(int ac, char **av);

//do move
void		ft_move(t_stack **a, t_stack **b, int coa, int cob);

//options
int			ft_lindex(t_stack **col);
void		ft_tindex(t_stack **a, t_stack **b);

//moves
void		ft_pa(t_stack **sta, t_stack **stb);
void		ft_pb(t_stack **sta, t_stack **stb);
void		ft_rra(t_stack **sta);
void		ft_rrb(t_stack **stb);
void		ft_rrr(t_stack **sta, t_stack **stb);
void		ft_ra(t_stack **sta);
void		ft_rb(t_stack **stb);
void		ft_rr(t_stack **sta, t_stack **stb);
void		ft_sa(t_stack **sta);
void		ft_sb(t_stack **stb);
void		ft_ss(t_stack **sta, t_stack **stb);

//sorting
int			ft_sorted(t_stack *col);
void		ft_short(t_stack **col);
void		ft_sort(t_stack **sta, t_stack **stb);

//steps
void		ft_stepcount(t_stack **sta, t_stack **stb);
void		ft_quickstep(t_stack **sta, t_stack **stb);

//tempft
int			ft_isdigit(int c);
int			ft_issign(char c);
int			ft_abs(int n);
long int	ft_atoi(const char *str);

//utils
void		ft_putstr(char *str);
void		ft_free(t_stack **col);
void		ft_error(t_stack **sta, t_stack **stb);

//validation
int			ft_valid(char **av);

//stack
t_stack		*ft_botstack(t_stack *col);
t_stack		*ft_2ndbotstack(t_stack *col);
int			ft_slinky(t_stack *col);
t_stack		*ft_newstack(int value);
void		ft_addbotstack(t_stack **col, t_stack *new);

#endif
