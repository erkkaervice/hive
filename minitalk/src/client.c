/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:33 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/27 16:43:46 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_bit(int pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(100);  // Adjusted for reliability and performance
}

static void	ft_send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		ft_send_bit(pid, (c & (1 << bit)));
		bit++;
	}
}

static void	ft_send(int pid, char *msg)
{
	while (*msg)
	{
		ft_send_char(pid, *msg);
		msg++;
	}
	// Send end-of-message delimiter (0xFF)
	ft_send_char(pid, 0xFF);
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