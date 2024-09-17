/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:56:15 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:29 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	str1[] = "kaikkihyvin";
	char	str2[] = "kaikkihuonosti";
	int		x;

	x = 9;
	printf("%s\n", str1);
	printf("%s\n", str2);
	if (ft_strncmp(str1, str2, x) == 0)
		printf("BUENO!\n");
	else
		printf("NO BUENO!\n");
	return (0);
}
*/
