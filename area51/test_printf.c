/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:24:25 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/05 11:42:22 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		ret_printf;
	int		ret_ft_printf;
	void	*ptr;

	ptr = (void *)0x12345678;
	ret_printf = printf("Original: Character: %c\n", 'A');
	ret_ft_printf = ft_printf("ft_printf: Character: %c\n", 'A');
	ret_printf = printf("Original: String: %s\n", "Hello");
	ret_ft_printf = ft_printf("ft_printf: String: %s\n", "Hello");
	ret_printf = printf("Original: Pointer: %p\n", ptr);
	ret_ft_printf = ft_printf("ft_printf: Pointer: %p\n", ptr);
	ret_printf = printf("Original: Integer: %d\n", 123);
	ret_ft_printf = ft_printf("ft_printf: Integer: %i\n", 123);
	ret_printf = printf("Original: Unsigned Integer: %u\n", 456);
	ret_ft_printf = ft_printf("ft_printf: Unsigned Integer: %u\n", 456);
	ret_printf = printf("Original: Hexadecimal (lc): %x\n", 0xABC);
	ret_ft_printf = ft_printf("ft_printf: Hexadecimal (lc): %x\n", 0xABC);
	ret_printf = printf("Original: Hexadecimal (uc): %X\n", 0xDEF);
	ret_ft_printf = ft_printf("ft_printf: Hexadecimal (uc): %X\n", 0xDEF);
	ret_printf = printf("Original: Percent sign: %%\n");
	ret_ft_printf = ft_printf("ft_printf: Percent sign: %%\n");
	ret_printf = printf("Original: Integer: %d\n", -123);
	ret_ft_printf = ft_printf("ft_printf: Integer: %d\n", -123);
	ret_printf = printf("Original: Empty string: %s\n", "");
	ret_ft_printf = ft_printf("ft_printf: Empty string: %s\n", "");
	ret_printf = printf("Original: Null terminator: %c\n", '\0');
	ret_ft_printf = ft_printf("ft_printf: Null terminator: %c\n", '\0');
	ret_printf = printf("Original: Null: %p\n", (NULL));
	ret_ft_printf = ft_printf("ft_printf: Null: %p\n", (NULL));
	return (0);
}
