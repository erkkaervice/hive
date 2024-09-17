/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:30:33 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:41 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	slinky(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*kreator(int size, char **strs, char *sep)
{
	char	*str;
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += slinky(strs[i]);
		i++;
	}
	length += slinky(sep) * (size -1);
	if (size <= 0)
		length = 1;
	str = (char *)malloc(sizeof(char) * length);
	if (!str)
		return (0);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = kreator(size, strs, sep);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[k++] = strs[i][j];
			j++;
		}
		j = 0;
		while (sep[j] && i != size - 1)
		{
			str[k++] = sep[j];
			j++;
		}
	}
	str[k] = '\0';
	return (str);
}

/*
int	main(void)
{
	char	str1[] = "ILVES VOITTAA";
	char	str2[] = "SUOMEN MESTARUUDEN";
	char	str3[] = "VUONNA 2024";
	char	*mission = ft_strjoin(3, (char *[]){str1, str2, str3}, " ");

	if (mission)
		printf("%s\n", mission);
	else
		printf("Mission failed\n");
	free(mission);
	return (0);
}
*/
