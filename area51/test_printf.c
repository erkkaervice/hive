/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:24:25 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/13 14:28:27 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret_printf;
	int	ret_ft_printf;

	ret_printf = printf("Original printf: Hello, world!\n");
	ret_ft_printf = ft_printf("Your ft_printf: Hello, world!\n");

	printf("Return value of printf: %d\n", ret_printf);
	printf("Return value of ft_printf: %d\n", ret_ft_printf);

	return (0);
}
