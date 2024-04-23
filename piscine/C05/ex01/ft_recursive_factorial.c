/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:36:33 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/31 13:52:32 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb -1));
}
/*
#include <stdio.h>

int	main(void)
{
	int	j;

	j = 5;
	printf("Is it 120? Yes it is %d\n", ft_recursive_factorial(j));
	return (0);
}
*/
