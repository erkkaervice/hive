/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/11 11:57:43 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdlib.h>

volatile sig_atomic_t	g_state = 0;

void	ft_bit(int sig, int *chr, int *bit)
{
	if (sig == SIGUSR1)
		*chr |= (1 << *bit);
	else if (sig == SIGUSR2)
		*chr &= ~(1 << *bit);
	(*bit)--;
}

void	ft_eom(int chr, pid_t last_pid)
{
	static char	*buffer = NULL;
	static int	index = 0;
	static int	buffer_size = 128;  // Initial buffer size
	int			i;

	// Allocate the initial buffer if not already allocated
	if (!buffer)
	{
		buffer = malloc(buffer_size);
		if (!buffer)
			ft_error("MEMORY ALLOCATION FAILED\n");
	}

	if (chr == '\0')  // End of message
	{
		buffer[index] = '\0';  // Null-terminate the string
		write(1, buffer, index);  // Print the entire message
		write(1, "\n", 1);  // Newline after message
		free(buffer);  // Free the allocated memory
		buffer = NULL;  // Reset buffer for the next message
		index = 0;
		buffer_size = 128;  // Reset buffer size
		if (kill(last_pid, SIGUSR1) == -1)
			ft_error("PROBLEM WITH SIGNAL, TRY TELEGRAM\n");
		g_state = 0;  // Reset state for new client
	}
	else
	{
		if (index >= buffer_size)
		{
			// Allocate a larger buffer (double the size)
			char *new_buffer = malloc(buffer_size * 2);
			if (!new_buffer)
				ft_error("MEMORY ALLOCATION FAILED\n");

			// Copy contents from the old buffer to the new one
			i = 0;
			while (i < index)
			{
				new_buffer[i] = buffer[i];
				i++;
			}

			// Free the old buffer and point to the new one
			free(buffer);
			buffer = new_buffer;
			buffer_size *= 2;  // Double the buffer size
		}
		buffer[index++] = chr;  // Store received character in buffer
	}
}

void	ft_receive(int sig, siginfo_t *info, void *birds)
{
	static int		chr = 0;
	static int		bit = 7;
	static pid_t	last_pid = 0;

	(void)birds;
	if (g_state == 0)
	{
		last_pid = info->si_pid;
		g_state = last_pid;
	}
	else if (info->si_pid != last_pid)
		return ;
	ft_bit(sig, &chr, &bit);
	if (bit < 0)
	{
		ft_eom(chr, last_pid);
		chr = 0;
		bit = 7;
	}
	if (kill(last_pid, SIGUSR1) == -1)
		ft_error("PROBLEM WITH SIGNAL, TRY TELEGRAM\n");
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
