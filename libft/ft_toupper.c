/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:58:26 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/09 13:22:15 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	usc;

	usc = (unsigned char)c;
	if (usc >= 'a' && usc <= 'z')
	{
		return (usc - ('a' - 'A'));
	}
	return (c);
}
