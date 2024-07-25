/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:29:55 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/25 17:52:11 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

t_stack	*ft_stack(int ac, char **av)
{
	t_stack	*tmp;
	t_stack	*new;
	int		i;

	tmp = NULL;
	i = 1;
	while (i < ac)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->val = ft_atoi(av[i]);
		new->next = tmp;
		tmp = new;
		i++;
	}
	return (tmp);
}

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
		ft_pb(stb, sta);
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
		return (write(2, "Error\n", 6), 1);
	return (0);
}

int	ft_cleaner(char **line, t_stack **sta, t_stack **stb)
{
	t_stack	*del;
	t_stack	*tmp;

	ft_strdel(line);
	tmp = *sta;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*sta = NULL;
	tmp = *stb;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stb = NULL;
	write(2, "Error\n", 6);
	return (0);
}

void	ft_result(t_stack **sta, t_stack **stb)
{
	if (!ft_sorted(*sta) && !(*stb))
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
	sta = ft_stack(ac, av);
	if (!sta)
		return (write(2, "Error\n", 6), 0);
	stb = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_compare(line, &sta, &stb))
			return (ft_cleaner(&line, &sta, &stb));
		ft_strdel(&line);
		line = get_next_line(0);
	}
	ft_result(&sta, &stb);
	return (0);
}
