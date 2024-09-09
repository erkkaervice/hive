/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/09 14:20:53 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t g_state = 0; // 0: g_oke=false, 1: g_oke=true

void	ft_receive(int sig, siginfo_t *info, void *birds)
{
	static int	chr = 0;
	static int	bit = 7;
	static pid_t last_pid = 0;

	(void)birds;

	if (g_state == 0) // Not currently processing a message
	{
		last_pid = info->si_pid; // Set the current PID
		g_state = 1; // Indicate that we are now processing a message
	}
	else if (info->si_pid != last_pid)
	{
		// If the PID does not match, ignore the signal
		return;
	}

	if (sig == SIGUSR1)
		chr |= (1 << bit); // Set the bit for SIGUSR1
	else if (sig == SIGUSR2)
		chr &= ~(1 << bit); // Clear the bit for SIGUSR2

	bit--;
	if (bit < 0)
	{
		// We have processed a full byte
		if (chr == '\0')
		{
			// End of message
			write(1, "\n", 1);
			if (kill(last_pid, SIGUSR1) == -1)
				ft_error("ERROR IN SENDING SIGNAL");
			g_state = 0; // Reset state for next message
		}
		else
		{
			// Print received character
			write(1, &chr, 1);
		}
		// Reset for the next byte
		chr = 0;
		bit = 7;
	}
	if (kill(last_pid, SIGUSR1) == -1)
		ft_error("ERROR IN SENDING SIGNAL");
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_receive;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa, NULL) == -1))
		ft_error("ERROR IN SETTING UP SIGNAL HANDLER");
	while (1)
		pause(); // Wait for signals
	return (0);
}
