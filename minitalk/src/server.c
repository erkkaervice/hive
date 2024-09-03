/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:20 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/03 15:37:40 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char g_data = 0; // Single global variable for character data

void handle_signal(int signal)
{
    static int bit_count = 0;

    if (signal == SIGUSR2)
    {
        g_data |= (1 << bit_count); // Set the bit if SIGUSR2
    }

    bit_count++;

    if (bit_count == 8)
    {
        if (g_data == '\0') // End of message
        {
            write(1, "\n", 1); // Newline for message end
        }
        else
        {
            write(1, &g_data, 1); // Output the character
        }

        g_data = 0; // Reset for next character
        bit_count = 0; // Reset bit count
    }
}

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = SA_RESTART | SA_NODEFER;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Error setting up signal handlers\n");
        return 1;
    }

    ft_printf("Server PID: %d\n", getpid());

    while (1)
    {
        pause(); // Wait for signals
    }
    return 0;
}
