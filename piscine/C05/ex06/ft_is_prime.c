/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:14:37 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:34 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (nb % i != 0)
		i++;
	if (i == nb)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	num;
	int	op;

	num = 12;
	op = (ft_is_prime(num));
	if (op == 1)
		printf("OPTIMUS PRIME\n");
	if (op == 0)
		printf("THESE ARE NOT THE PRIMES YOU WERE LOOKING FOR\n");
	return (0);
}
*/
