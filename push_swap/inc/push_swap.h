/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:27 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/27 14:34:34 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_col
{
	int				val;
	int				ind;
	int				pos;
	int				tgt;
	int				coa;
	int				cob;
	struct s_col	*next;
}	t_col;

//index
t_col		*ft_value(int ac, char **av);
void		ft_index(t_col *col_a, int cos);

//main
int			main(int ac, char **av);

//do move
void		ft_move(t_col **a, t_col **b, int coa, int cob);

//options
int			ft_heli(t_col **col);
void		ft_aim(t_col **a, t_col **b);

//moves
void		ft_pa(t_col **col_a, t_col **col_b);
void		ft_pb(t_col **col_a, t_col **col_b);
void		ft_rra(t_col **col_a);
void		ft_rrb(t_col **col_b);
void		ft_rrr(t_col **col_a, t_col **col_b);
void		ft_ra(t_col **col_a);
void		ft_rb(t_col **col_b);
void		ft_rr(t_col **col_a, t_col **col_b);
void		ft_sa(t_col **col_a);
void		ft_sb(t_col **col_b);
void		ft_ss(t_col **col_a, t_col **col_b);

//sorting
int			ft_sorted(t_col *col);
void		ft_short(t_col **col);
void		ft_sort(t_col **col_a, t_col **col_b);

//steps
void		ft_stepcount(t_col **col_a, t_col **col_b);
void		ft_quickstep(t_col **col_a, t_col **col_b);

//tempft
int			ft_isdigit(int c);
int			ft_issign(char c);
int			ft_isspace(int c);
int			ft_abs(int n);
long int	ft_atoi(const char *str);

//utils
void		ft_putstr(char *str);
void		ft_free(t_col **col);
void		ft_error(t_col **col_a, t_col **col_b);

//validation
int			ft_valid(char **av);

//wtc
t_col		*ft_lobby(t_col *col);
t_col		*ft_stairs(t_col *col);
int			ft_slinky(t_col *col);
t_col		*ft_trump(int value);
void		ft_lobbybar(t_col **col, t_col *new);

#endif
