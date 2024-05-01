/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:35:43 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/01 16:36:55 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	size_t	i;

	if (!haystack && !n)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n--)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i)
			&& *(needle + i) && i <= n)
		{
			if (!*(needle + i + 1))
				return ((char *)haystack);
			i++;
		}
		haystack++;
	}
	return (NULL);
}
