/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:44:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/17 13:40:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size < 1)
		return (count);
	while (src[i] && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}
/*
int	main(void)
{
	char	lause[] = "Boil 'em, mash 'em, stick 'em in a stew";
	char	kohde[100];
	unsigned int	size;

	size = 100;
	printf("%s\n", lause);
	printf("How many potatoes? %d\n", ft_strlcpy(kohde, lause, size));
	return (0);
}
*/
