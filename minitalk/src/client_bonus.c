/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:43 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/05 16:18:06 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack;

void	ft_acker(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
}

void	ft_bits(int server_pid, int bit)
{
	if (bit)
	{
		if (kill(server_pid, SIGUSR1) == -1)
			ft_error("ERROR IN SENDING SIGUSR1");
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
			ft_error("ERROR IN SENDING SIGUSR2");
	}
	while (!g_ack)
		pause();
	g_ack = 0;
}

void	ft_send(int server_pid, char c, int end)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		ft_bits(server_pid, (c >> bit) & 1);
		bit--;
	}
	if (end && !c)
		ft_printf("VERY SUCCESS!\n");
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*msg;
	struct sigaction	sa;

	if (argc != 3 || !(*argv[2]))
		ft_error("USAGE: ./client <server_pid> <message>");
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		ft_error("INVALID SERVER PID");
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = ft_acker;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("ERROR IN SETTING UP SIGNAL HANDLER");
	msg = argv[2];
	while (*msg)
		ft_send(server_pid, *msg++, 0);
	ft_send(server_pid, '\0', 1);
	return (0);
}
