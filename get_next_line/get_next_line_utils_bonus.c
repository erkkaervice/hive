/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:39:04 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/06 12:08:35 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_newstr(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
	{
		return (NULL);
	}
	*str = '\0';
	return (str);
}

char	*ft_gnlchr(const char *s, int c)
{
	if (!s)
	{
		return (NULL);
	}
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	else
	{
		return (NULL);
	}
}

char	*ft_gnljoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*stp;

	if (!s)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s))
	{
		return (ft_newstr(0));
	}
	if (len > (ft_strlen(s) - start))
	{
		len = ft_strlen(s) - start;
	}
	str = ft_newstr(len);
	if (!str)
		return (NULL);
	stp = str;
	s += start;
	while (len-- && *s)
	{
		*str++ = *s++;
	}
	*str = '\0';
	return (stp);
}
