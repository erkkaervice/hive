/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/05 15:41:20 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_recieve(int sig, siginfo_t *info, void *birds)
{
	static int	chr = 0;
	static int	bit = 7;

	(void)birds;
	if (sig == SIGUSR1)
		chr |= (1 << bit);
	else
		chr &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		if (chr == '\0')
			write(1, "\n", 1);
		else
			write(1, &chr, 1);
		chr = 0;
		bit = 7;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_error("ERROR IN SENDING SIGNAL");
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
