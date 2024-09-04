/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:20 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/04 17:57:28 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_recieve(int sig, siginfo_t *info, void *birds)
{
	static int	chr = 0;
	static int	bit = 7;
	sigset_t	block_mask;

	(void)birds;

	// Block further signals while processing the current one
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGUSR1);
	sigaddset(&block_mask, SIGUSR2);
	sigprocmask(SIG_BLOCK, &block_mask, NULL);

	// Process the signal
	if (sig == SIGUSR1)
		chr |= (1 << bit);
	else
		chr &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		if (chr == '\0')
			ft_printf("\n");
		else
			write(1, &chr, 1);
		chr = 0;
		bit = 7;
	}

	// Send acknowledgment signal back to the client
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_error("ERROR IN SENDING SIGNAL");

	// Unblock signals after processing
	sigprocmask(SIG_UNBLOCK, &block_mask, NULL);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_recieve;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa, NULL) == -1))
		ft_error("ERROR IN SETTING UP SIGNAL HANDLER");
	while (1)
		pause();
	return (0);
}