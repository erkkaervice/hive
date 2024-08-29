/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:33 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/29 16:01:23 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		bit++;
	}
}

static void	ft_chunk(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		ft_bits(pid, msg[i]);
		i++;
	}
}

static void	ft_send(int pid, char *msg)
{
	ft_bits(pid, '\1');
	ft_chunk(pid, msg);
	ft_bits(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	ft_send(pid, av[2]);
	return (0);
}
