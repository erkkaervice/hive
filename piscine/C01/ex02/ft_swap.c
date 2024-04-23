/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:22 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/17 13:49:50 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}
/*
int	main(void)
{
	int	x;
	int	y;

	x = 1;
	y = 2;
	printf("%d%d\n", x, y);
	ft_swap(&x, &y);
	printf("%d%d\n", x, y);
	return (0);
}
*/
