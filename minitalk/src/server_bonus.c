/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/11 13:41:43 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_state = 0;

void	ft_bit(int sig, int *chr, int *bit)
{
	if (sig == SIGUSR1)
		*chr |= (1 << *bit);
	else if (sig == SIGUSR2)
		*chr &= ~(1 << *bit);
	(*bit)--;
}

void	ft_buffer(int chr, int *index, int *buffer_size, char **buffer)
{
	int		i;
	int		old_index;
	char	*new_buffer;

	if (*index >= *buffer_size)
	{
		new_buffer = malloc(*buffer_size * 2);
		if (!new_buffer)
			ft_error("MEMORY ALLOCATION FAILED\n");
		i = 0;
		old_index = *index;
		while (i < old_index)
		{
			new_buffer[i] = (*buffer)[i];
			i++;
		}
		free(*buffer);
		*buffer = new_buffer;
		*buffer_size *= 2;
	}
	(*buffer)[*index] = chr;
	(*index)++;
}

void	ft_process(int chr, pid_t last_pid)
{
	static char	*buffer = NULL;
	static int	index = 0;
	static int	buffer_size = 128;

	if (!buffer)
	{
		buffer = malloc(buffer_size);
		if (!buffer)
			ft_error("MEMORY ALLOCATION FAILED\n");
	}
	if (chr == '\0')
	{
		if (buffer)
		{
			buffer[index] = '\0';
			write(1, buffer, index);
			write(1, "\n", 1);
			free(buffer);
		}
		buffer = NULL;
		index = 0;
		buffer_size = 128;
		if (kill(last_pid, SIGUSR1) == -1)
			ft_error("PROBLEM WITH SIGNAL, TRY TELEGRAM\n");
		g_state = 0;
	}
	else
		ft_buffer(chr, &index, &buffer_size, &buffer);
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
		ft_process(chr, last_pid);
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
