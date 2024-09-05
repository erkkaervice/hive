/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:33 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/05 12:07:59 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack;

void	ft_acker(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
}

void	ft_confirm(int end, int bit)
{
	if (end && bit == 0)
		ft_printf("VERY SUCCESS!\n");
}

void	ft_bits(int server_pid, int bit)
{
	int		retries;
	int		backoff;
	sigset_t	sigset;
	struct timespec timeout;

	retries = 5;
	backoff = 1;

	// Set up the signal set to wait for SIGUSR1 (acknowledgment)
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);

	// Timeout value: 1 second
	timeout.tv_sec = 1;
	timeout.tv_nsec = 0;

	while (retries--)
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

		// Use sigtimedwait instead of pause to wait for a specific signal with a timeout
		if (sigtimedwait(&sigset, NULL, &timeout) == -1)
		{
			ft_printf("Retrying in %d seconds...\n", backoff);
			sleep(backoff);
			backoff *= 2;
		}
		else
		{
			// Acknowledgment received
			break;
		}
	}

	if (retries == 0)
		ft_error("FAILED TO RECEIVE ACKNOWLEDGMENT");
}


void	ft_send(int server_pid, char c, int end)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		ft_bits(server_pid, (c & (1 << bit)) != 0);
		ft_confirm(end, bit);
		bit--;
	}
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
	{
		ft_send(server_pid, *msg, 0);
		msg++;
	}
	ft_send(server_pid, '\0', 1);

	return (0);
}
