/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:35:51 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/01 16:36:56 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	const char	*last_hit;

	last_hit = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last_hit = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return ((char *)last_hit);
}
