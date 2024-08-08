/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:29:55 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/08 16:52:26 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_compare(char *line, t_stack **sta, t_stack **stb)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_sa(sta);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_sb(stb);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss(sta, stb);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_pa(sta, stb);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_pb(sta, stb);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_ra(sta);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rb(stb);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr(sta, stb);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_rra(sta);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_rrb(stb);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_rrr(sta, stb);
	else
		ft_error(sta, stb);
	return (0);
}

int	ft_cleaner(char **line, t_stack **sta, t_stack **stb)
{
	ft_strdel(line);
	ft_error(sta, stb);
	return (0);
}

void	ft_result(t_stack **sta, t_stack **stb)
{
	if (ft_sorted(*sta) && !(*stb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	char	*line;

	if (ac < 2)
		return (0);
	sta = ft_value(ac, av);
	if (!sta)
		ft_error(&sta, NULL);
	stb = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (ft_compare(line, &sta, &stb))
			return (ft_cleaner(&line, &sta, &stb));
		ft_strdel(&line);
		line = get_next_line(0);
	}
	ft_result(&sta, &stb);
	return (0);
}
