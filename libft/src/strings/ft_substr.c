/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:03:14 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/13 16:30:18 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
