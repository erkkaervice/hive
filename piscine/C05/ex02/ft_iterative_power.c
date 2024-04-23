/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:49:12 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/31 13:51:19 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		i *= nb;
		power--;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int	j;

	j = 3;
	printf("Is it 27? Yes it is  %d\n", ft_iterative_power(j, j));
	return (0);
}
*/
