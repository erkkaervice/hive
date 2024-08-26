/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/26 14:00:12 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

t_msg	g_msg = {0, 0};

static void	ft_recieve(int sig)
{
	if (sig == SIGUSR2)
		g_msg.chr |= (1 << g_msg.btc);
	g_msg.btc++;
	if (g_msg.btc == 8)
	{
		write(1, &g_msg.chr, 1);
		g_msg.chr = 0;
		g_msg.btc = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int				pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_handler = ft_recieve;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("sigaction");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}