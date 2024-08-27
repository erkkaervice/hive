/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:20 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/27 16:43:45 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg = {0, 0, {0}, 0};  // Global variable justified for message storage

void	reset_message(void)
{
	g_msg.chr = 0;
	g_msg.btc = 0;
	g_msg.bix = 0;
	ft_memset(g_msg.buf, 0, sizeof(g_msg.buf));  // Clear buffer
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
		g_msg.chr |= (1 << g_msg.btc);  // Set the bit if SIGUSR2 received

	g_msg.btc++;
	if (g_msg.btc == 8)  // Full byte received
	{
		if (g_msg.chr == 0xFF)  // End-of-message delimiter
		{
			write(1, g_msg.buf, g_msg.bix);  // Output the message
			write(1, "\n", 1);  // Newline after message
			reset_message();  // Reset buffer for next message
		}
		else
		{
			if (g_msg.bix < (int)(sizeof(g_msg.buf) - 1))
			{
				g_msg.buf[g_msg.bix++] = g_msg.chr;  // Store character
			}
			else
			{
				ft_printf("Message buffer overflow\n");
				reset_message();  // Reset buffer on overflow
			}
			g_msg.chr = 0;  // Reset character
			g_msg.btc = 0;  // Reset bit count
		}
	}
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;  // Restart interrupted system calls
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up signal handlers\n");
		return (1);
	}

	ft_printf("Server PID: %d\n", getpid());

	while (1)
	{
		pause();  // Wait for signals
	}

	return (0);
}