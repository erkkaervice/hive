/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:00 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/11 14:34:28 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit(int sig, int *chr, int *bit)
{
	if (sig == SIGUSR1)
		*chr |= (1 << *bit);
	else if (sig == SIGUSR2)
		*chr &= ~(1 << *bit);
	(*bit)--;
}

void	ft_signal(int server_pid, int signal)
{
	if (kill(server_pid, signal) == -1)
		ft_error("PROBLEM WITH SIGNAL, TRY TELEGRAM\n");
}
