/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:07:22 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	squirtle;

	squirtle = 1;
	if (nb > 0)
	{
		while (squirtle * squirtle <= nb)
		{
			if (squirtle * squirtle == nb)
				return (squirtle);
			if (squirtle > 46340)
				return (0);
			squirtle++;
		}
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 25;
	printf("Is it 5? Yes it is %d\n", ft_sqrt(i));
	return (0);
}
*/
