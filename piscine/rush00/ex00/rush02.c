/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:03:17 by likong            #+#    #+#             */
/*   Updated: 2024/09/17 15:28:48 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char ch);

void	choice_element(int i, int j, int x, int y)
{
	if ((j == 0 || j == x - 1) && i == 0)
		putchar('A');
	else if ((j == 0 || j == x - 1) && i == y - 1)
		putchar('C');
	else if ((j == 0 || j == x - 1) && i != 0 && i != y - 1)
		putchar('B');
	else if (j != 0 && j != x - 1 && (i == 0 || i == y - 1))
		putchar('B');
	else
		write(1, " ", 1);
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			choice_element(i, j, x, y);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
