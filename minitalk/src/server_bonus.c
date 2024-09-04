/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/04 12:04:10 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_signal	g_signal;

static void	btoc(int sig, siginfo_t *info, void *other)
{
	pid_t		client_pid;

	(void) other;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		g_signal.current_byte = g_signal.current_byte | (1 << g_signal.bit);
	g_signal.bit --;
	if (g_signal.bit == -1)
	{
		if (g_signal.current_byte == '\0')
			ft_printf("\n");
		else
			write(1, &(g_signal.current_byte), 1);
		g_signal.current_byte = 0;
		g_signal.bit = 7;
	}
	if (kill (client_pid, SIGUSR1) == -1)
		ft_error("ERROR IN SENDING SIGNAL");
}

int	main(void)
{
	struct sigaction	sa;

	g_signal.current_byte = 0;
	g_signal.bit = 7;
	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = btoc;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa, NULL) == -1))
		ft_error("ERROR IN SETTING UP SIGNAL HANDLER");
	while (1)
		pause();
	return (0);
}