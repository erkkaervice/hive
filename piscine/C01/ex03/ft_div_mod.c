/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:01:19 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/17 13:50:23 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	x;
	int	y;
	int	d;
	int	m;

	x = 10;
	y = 3;
	ft_div_mod(x, y, &d, &m);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", d);
	printf("%d\n", m);
	return (0);
}
*/
