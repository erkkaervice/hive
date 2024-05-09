/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:32:46 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/09 19:05:19 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static unsigned int	ft_signmark(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

static char	*ft_newstr(size_t n)
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

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*str;

	nbr = ft_signmark(n);
	sign = 0;
	len = ft_nbrlen(n);
	str = ft_newstr(len);
	if (!str)
		return (NULL);
	if (n < 0)
		sign = 1;
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = '0' + nbr % 10;
		nbr /= 10;
	}
	if (sign)
	{
		str[0] = '-';
	}
	return (str);
}
