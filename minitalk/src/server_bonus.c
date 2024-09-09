/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/09 12:36:16 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_oke = false;

int	ft_verify(siginfo_t *info, pid_t *current_pid)
{
	if (g_oke == true && info->si_pid != *current_pid) 
		return (-1);
	else if (g_oke == false)
	{
		*current_pid = info->si_pid;
		g_oke = true;
	}
	return (0);
}

void	ft_recieve(int sig, siginfo_t *info, void *birds)
{
	static int	chr = 0;
	static int	bit = 7;
	static pid_t	current_pid = 0;

	(void)birds;
	if (ft_verify(info, &current_pid) == -1)
		return ;
	if (sig == SIGUSR1)
		chr |= (1 << bit);
	else
		chr &= ~(1 << bit);
	bit--;
	if (bit < 0)
	{
		if (chr == '\0')
		{
			write(1, "\n", 1);
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_error("ERROR IN SENDING SIGNAL");
			g_oke = false;
		}
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
