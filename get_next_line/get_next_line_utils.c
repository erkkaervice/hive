/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:15:24 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/28 17:02:58 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
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

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*sta;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	sta = dst;
	if (!s1 || !dst)
	{
		errno = ENOMEM;
		free (dst);
		return (NULL);
	}
	while (*s1)
	{
		*dst = *s1;
		dst++;
		s1++;
	}
	*dst = '\0';
	free (dst);
	return (sta);
}

char	*ft_strjoinwb(char *buf, const char *con)
{
	size_t	bul;
	size_t	col;
	char	*result;
	char	*rep;
	char	*src;

	bul = 0;
	if (!buf && !con)
		return (NULL);
	if (buf)
		bul = ft_strlen(buf);
	col = ft_strlen(con);
	result = (char *)malloc(sizeof(char) * (bul + col + 1));
	if (!result)
		return (NULL);
	rep = result;
	src = buf;
	while (src && *src)
		*rep++ = *src++;
	src = (char *)con;
	while (src && *src)
		*rep++ = *src++;
	*rep = '\0';
	free(buf);
	return (result);
}
