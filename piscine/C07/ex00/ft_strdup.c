/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:58:34 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:37 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

unsigned int	slinky(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*cp_slinky(char *str, char *dst)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *src)
{
	unsigned int	i;
	char			*dst;

	i = slinky(src);
	dst = (char *)malloc(sizeof(char) * i);
	if (!(dst))
		return (0);
	return (cp_slinky(src, dst));
}

/*
int	main(void)
{
	char	str1[] = "pOtTaTo!";
	char	*mission;

	mission = ft_strdup(str1);
	if (mission == 0)
		printf("Mission failed");
	else
		printf("%s\n", mission);
	free(mission);
	return (0);
}
*/
