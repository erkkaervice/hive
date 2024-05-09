/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:06:19 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/09 14:40:44 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dsp;

	dsp = dst;
	if (!dst && !src)
	{
		return (dst);
	}
	while (n--)
	{
		*(char *)dst++ = *(const char *)src++;
	}
	return (dsp);
}
