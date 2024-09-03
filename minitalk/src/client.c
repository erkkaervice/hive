/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:33 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/03 15:47:34 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bit(pid_t server_pid, int bit)
{
    if (bit)
    {
        if (kill(server_pid, SIGUSR2) == -1)
        {
            ft_printf("Error sending SIGUSR2\n");
            exit(1);
        }
    }
    else
    {
        if (kill(server_pid, SIGUSR1) == -1)
        {
            ft_printf("Error sending SIGUSR1\n");
            exit(1);
        }
    }
    usleep(5000); // Increased delay to ensure reliable transmission
}

void send_char(pid_t server_pid, char c)
{
    send_bit(server_pid, (c & 1));          // Send the least significant bit
    send_bit(server_pid, (c >> 1) & 1);     // Send the next bit
    send_bit(server_pid, (c >> 2) & 1);     // Send the next bit
    send_bit(server_pid, (c >> 3) & 1);     // Send the next bit
    send_bit(server_pid, (c >> 4) & 1);     // Send the next bit
    send_bit(server_pid, (c >> 5) & 1);     // Send the next bit
    send_bit(server_pid, (c >> 6) & 1);     // Send the next bit
    send_bit(server_pid, (c >> 7) & 1);     // Send the most significant bit
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ft_printf("Usage: ./client <PID> <message>\n");
        return 1;
    }

    pid_t server_pid = (pid_t)ft_atoi(argv[1]);
    char *message = argv[2];

    while (*message)
    {
        send_char(server_pid, *message++);
    }
    send_char(server_pid, '\0'); // Send null terminator to indicate end of message

    return 0;
}
