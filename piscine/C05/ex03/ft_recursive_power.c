/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:12:01 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/31 13:51:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (power > 1)
		return (i * ft_recursive_power(i, power -1));
	else
		return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int	j;

	j = 5;
	printf("Is it 3125? Yes it is %d\n", ft_recursive_power(j, j));
	return (0);
}
*/
