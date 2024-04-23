/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:01:42 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/17 13:41:53 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;
	char			c;
	int				cap;

	i = 0;
	cap = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (cap == 1 && c >= 'a' && c <= 'z')
			str[i] = str[i] - 32;
		else if (cap == 0 && c >= 'A' && c <= 'Z')
			str[i] = str[i] + 32;
		if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
			cap = 1;
		else
			cap = 0;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str1[] = "potatoes run the world";

	printf("%s\n", str1);
	printf("%s\n", ft_strcapitalize(str1));
	return (0);
}
*/
