/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:20 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/29 16:00:57 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_msg	g_msg = {NULL, 0, 0, 0};

void	reset_message(void)
{
	if (g_msg.buf)
	{
		free(g_msg.buf);
		g_msg.buf = NULL;
	}
	g_msg.chr = 0;
	g_msg.btc = 0;
	g_msg.bix = 0;
}

void	handle_message_start_end(void)
{
	if (g_msg.chr == '\1')
	{
		reset_message();
		g_msg.buf = malloc(BUFFER_SIZE);
		if (!g_msg.buf)
		{
			ft_printf("Memory allocation failed\n");
			exit(1);
		}
	}
	else if (g_msg.chr == '\0')
	{
		if (g_msg.buf)
		{
			write(1, g_msg.buf, g_msg.bix);
			free(g_msg.buf);
			g_msg.buf = NULL;
		}
		write(1, "\n", 1);
		reset_message();
	}
}

void	handle_buffer_allocation(void)
{
	char	*new_buf;
	size_t	new_size;

	if (g_msg.buf == NULL)
	{
		g_msg.buf = malloc(BUFFER_SIZE);
		if (!g_msg.buf)
		{
			ft_printf("Memory allocation failed\n");
			exit(1);
		}
	}
	else if (g_msg.bix >= BUFFER_SIZE)
	{
		new_size = g_msg.bix + BUFFER_SIZE;
		new_buf = realloc(g_msg.buf, new_size);
		if (!new_buf)
		{
			ft_printf("Memory reallocation failed\n");
			free(g_msg.buf);
			exit(1);
		}
		g_msg.buf = new_buf;
	}
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
		g_msg.chr |= (1 << g_msg.btc);
	g_msg.btc++;
	if (g_msg.btc == 8)
	{
		if (g_msg.chr == '\1' || g_msg.chr == '\0')
			handle_message_start_end();
		else
		{
			handle_buffer_allocation();
			if (g_msg.bix < BUFFER_SIZE || g_msg.buf != NULL)
				g_msg.buf[g_msg.bix++] = g_msg.chr;
		}
		g_msg.chr = 0;
		g_msg.btc = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up signal handlers\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
