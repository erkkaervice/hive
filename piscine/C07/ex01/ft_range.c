/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:35:27 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:38 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int				*array;
	unsigned int	i;

	i = 0;
	if (min >= max)
		return (0);
	array = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

/*
int	main(void)
{
	int	range[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	first;
	int	last;
	int	i;
	int	*mission;

	first = range[0];
	last = range[8];
	i = 0;
	mission = ft_range(first, last);
	if (mission == 0)
	{
		printf("Mission failed\n");
		return (1);
	}
	while (i < (last - first))
	{
		printf("%d\n", mission[i]);
		i++;
	}
	free(mission);
	return (0);
}
*/
