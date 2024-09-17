/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:20:37 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:31 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str [i] != '\0')
		i++;
	write(1, str, i);
}
/*
int	main(void)
{
	char	kukkuu[] = "hello";

	ft_putstr(kukkuu);
	return (0);
}
*/
