/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:39:22 by eala-lah          #+#    #+#             */
/*   Updated: 2024/04/26 18:44:48 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
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
