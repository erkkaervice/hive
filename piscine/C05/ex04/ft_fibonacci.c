/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:27:56 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/31 13:50:54 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	i;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
	{
		i = ft_fibonacci(index -1) + ft_fibonacci(index -2);
		return (i);
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	j;
	int	k;
	int	l;

	j = 4;
	k = 8;
	l = 13;
	printf("Is it 3? Yes it is : %d\n", ft_fibonacci(j));
	printf("Is it 21? Yes it is : %d\n", ft_fibonacci(k));
	printf("Is it 233? Yes it is : %d\n", ft_fibonacci(l));
	return (0);
}
*/
