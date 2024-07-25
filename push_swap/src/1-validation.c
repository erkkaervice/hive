/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-validation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:00:31 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/25 16:21:59 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *sta)
{
	if (!sta || !sta->next)
		return (1);
	while (sta->next != NULL)
	{
		if (sta->val > sta->next->val)
			return (0);
		sta = sta->next;
	}
	return (1);
}

static int	ft_number(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	return (av[i] == '\0');
}

static int	ft_zero(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]))
		i++;
	while (av[i] == '0')
		i++;
	return (av[i] == '\0');
}

static int	ft_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_valid(char **av)
{
	int	i;
	int	j;

	if (!av[1] || !av[1][0])
		return (0);
	j = 0;
	i = 1;
	while (av[i])
	{
		if (!ft_number(av[i]))
			return (0);
		if (ft_zero(av[i]))
			j++;
		i++;
	}
	return (j <= 1 && !ft_duplicate(av));
}
