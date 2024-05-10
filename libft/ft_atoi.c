/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:32 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/10 15:38:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_space(int c)
{
	if ((c > 8 && c < 14)
		|| (c == 32))
	{
		return (1);
	}
	return (0);
}

static int	ft_digit(int c)
{
	if (c > 47 && c < 58)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char const *str)
{
	long long int	n;
	int				sign;
	long long int	dig;

	n = 0;
	sign = 1;
	while (*str && ft_space(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (*str && ft_digit(*str))
	{
		dig = *str - '0';
		n = n * 10 + sign * dig;
		str++;
	}
	return ((int)n);
}
