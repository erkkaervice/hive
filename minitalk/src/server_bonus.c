/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/10 16:25:02 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_state = 0;

void	process_bit(int sig, int *chr, int *bit)
{
	if (sig == SIGUSR1)
		*chr |= (1 << *bit);
	else if (sig == SIGUSR2)
		*chr &= ~(1 << *bit);
	(*bit)--;
}

void	process_end_of_message(int chr, pid_t last_pid)
{
	if (chr == '\0')
	{
		write(1, "\n", 1);
		if (kill(last_pid, SIGUSR1) == -1)
			ft_error("ERROR IN SENDING SIGNAL");
		g_state = 0;
	}
	else
		write(1, &chr, 1);
}

void	ft_receive(int sig, siginfo_t *info, void *context)
{
	static int		chr = 0;
	static int		bit = 7;
	static pid_t	last_pid = 0;

	(void)context;
	if (g_state == 0)
	{
		last_pid = info->si_pid;
		g_state = last_pid;
	}
	else if (info->si_pid != last_pid)
		return ;
	process_bit(sig, &chr, &bit);
	if (bit < 0)
	{
		process_end_of_message(chr, last_pid);
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
		pause();
	return (0);
}
