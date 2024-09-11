/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:43 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/11 14:09:34 by eala-lah         ###   ########.fr       */
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
	int	retries;

	retries = 0;
	while (retries < MAX_RETRIES)
	{
		if (bit)
			ft_signal(server_pid, SIGUSR1);
		else
			ft_signal(server_pid, SIGUSR2);
		usleep(100);
		while (!g_ack && retries < MAX_RETRIES)
		{
			usleep(RETRY_DELAY);
			retries++;
		}
		if (g_ack)
		{
			g_ack = 0;
			return ;
		}
	}
	ft_error("SERVER IS BUSY, TRY AGAIN LATER\n");
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
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = ft_acker;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("ERROR IN SETTING UP SIGNAL HANDLER");
	msg = argv[2];
	while (*msg)
		ft_send(server_pid, *msg++, 0);
	ft_send(server_pid, '\0', 1);
	return (0);
}
