/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:17:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:24:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	usc;

	usc = (unsigned char)c;
	if (usc >= 'A' && usc <= 'Z')
		return (usc + ('a' - 'A'));
	return (c);
}
