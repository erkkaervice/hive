/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:27 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/25 17:08:17 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int				val;
	int				ind;
	int				pos;
	int				tgt;
	int				soa;
	int				sob;
	struct s_stack	*next;
}	t_stack;

//1-validation
int			ft_valid(char **av);

//2-stacking
int			ft_stalen(t_stack *sta);
t_stack		*ft_newstack(int value);
t_stack		*ft_botstack(t_stack *sta);
t_stack		*ft_2ndbotstack(t_stack *sta);
void		ft_addbotstack(t_stack **sta, t_stack *new);

//3-indexing
int			ft_lindex(t_stack **sta);
void		ft_tindex(t_stack **a, t_stack **b);
void		ft_index(t_stack *sta, int sts);

//4-sorting
int			ft_sorted(t_stack *sta);
void		ft_short(t_stack **sta);
void		ft_sort(t_stack **sta, t_stack **stb);

//5-moving
void		ft_move(t_stack **a, t_stack **b, int soa, int sob);

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
void		ft_stepcount(t_stack **sta, t_stack **stb);
void		ft_quickstep(t_stack **sta, t_stack **stb);

#endif
