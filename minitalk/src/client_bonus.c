/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:43 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/04 15:37:55 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_res;

void	ft_handler(int sig)
{
	if (sig == SIGUSR1)
		g_res = 1;
}

void	ft_confirm(int end, int bit)
{
	while (g_res == 0)
		pause();
	if (end && (bit == 0))
		ft_printf("Received\n");
	g_res = 0;
}

void	ft_send(int server_pid, char c, int end)
{
	int					bit;
	struct sigaction	sa;

	bit = 7;
	g_res = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = ft_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("ERROR IN SETTING UP SIGNAL HANDLER");
	while (bit >= 0)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_error("ERROR IN SENDING SIGNAL");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_error("ERROR IN SENDING SIGNAL");
		}
		ft_confirm(end, bit);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*msg;

	if (argc != 3 || !(*argv[2]))
		ft_error("ERROR IN INPUTS");
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		ft_error("ERROR IN INPUTS");
	msg = argv[2];
	while (*msg)
	{
		ft_send(server_pid, *msg, 0);
		msg++;
	}
	ft_send(server_pid, *msg, 1);
	return (0);
}
