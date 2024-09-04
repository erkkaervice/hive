/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:53 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/04 13:14:47 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void btoc(int sig, siginfo_t *info, void *context)
{
    static int current_byte = 0;
    static int bit = 7;

    (void)context;  // Unused parameter
    if (sig == SIGUSR1)
    {
        current_byte |= (1 << bit);
    }
    else if (sig == SIGUSR2)
    {
        current_byte &= ~(1 << bit);
    }
    bit--;
    if (bit == -1)
    {
        if (current_byte == '\0')
        {
            ft_printf("\n");  // End of message
        }
        else
        {
            write(1, &current_byte, 1);  // Print received byte
        }
        current_byte = 0;
        bit = 7;  // Reset for next byte
    }
    if (kill(info->si_pid, SIGUSR1) == -1)
        ft_error("ERROR IN SENDING SIGNAL");
}

int main(void)
{
    struct sigaction sa;

    ft_printf("Server PID: %d\n", getpid());

    // Initialize sigaction for handling signals
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = btoc;

    if ((sigaction(SIGUSR1, &sa, NULL) == -1) || (sigaction(SIGUSR2, &sa, NULL) == -1))
    {
        ft_error("ERROR IN SETTING UP SIGNAL HANDLER");
    }

    while (1)
    {
        pause();  // Wait for signals indefinitely
    }

    return 0;
}