/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:16:18 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:39 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*size;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = (int *)malloc(sizeof(int) * (max - min));
	if (size == 0)
		return (-1);
	else
	{
		i = -1;
		while (++i < max - min)
			size[i] = min + i;
		*range = size;
		return (i);
	}
}

/*
int	main(void)
{
	int	range[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	first;
	int	last;
	int	*length = 0;
	int	mission;

	first = range[0];
	last = range[8];
	mission = ft_ultimate_range(&length, first, last);
	if (length == 0)
	{
		printf("Mission failed\n");
		return (1);
	}
	printf("%d\n", mission);
	free(length);
	return (0);
}
*/
