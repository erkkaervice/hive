/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:40:28 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/31 13:52:41 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (i);
	while (nb > 0)
	{
		i *= nb;
		nb--;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int	j;

	j = 4;
	printf("Is it 24? Yes it is %d\n", ft_iterative_factorial(j));
	return (0);
}
*/
