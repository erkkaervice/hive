/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:17:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/09 13:22:16 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	usc;

	usc = (unsigned char)c;
	if (usc >= 'A' && usc <= 'Z')
	{
		return (usc + ('a' - 'A'));
	}
	return (c);
}
