/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:33 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/04 16:16:52 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack;

void signal_handler(int sig)
{
    if (sig == SIGUSR1)
        g_ack = 1;
}

void send_bit(int server_pid, int bit)
{
    if (bit)
    {
        if (kill(server_pid, SIGUSR1) == -1)
            ft_error("ERROR IN SENDING SIGUSR1");
    }
    else
    {
        if (kill(server_pid, SIGUSR2) == -1)
            ft_error("ERROR IN SENDING SIGUSR2");
    }
    while (g_ack == 0)
        pause();
    g_ack = 0;
}

/* Send a character to the server bit by bit */
void send_character(int server_pid, char c)
{
    send_bit(server_pid, (c & 0x80) != 0); // Send most significant bit
    send_bit(server_pid, (c & 0x40) != 0);
    send_bit(server_pid, (c & 0x20) != 0);
    send_bit(server_pid, (c & 0x10) != 0);
    send_bit(server_pid, (c & 0x08) != 0);
    send_bit(server_pid, (c & 0x04) != 0);
    send_bit(server_pid, (c & 0x02) != 0);
    send_bit(server_pid, (c & 0x01) != 0); // Send least significant bit
}

/* Main function to handle sending the message */
int main(int argc, char **argv)
{
    int server_pid;
    char *msg;
    struct sigaction sa;

    if (argc != 3 || !(*argv[2]))
        ft_error("USAGE: ./client_bonus <server_pid> <message>");

    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0)
        ft_error("INVALID SERVER PID");

    // Setup signal handler
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = signal_handler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        ft_error("ERROR IN SETTING UP SIGNAL HANDLER");

    // Send each character in the message
    msg = argv[2];
    while (*msg)
    {
        send_character(server_pid, *msg);
        msg++;
    }

    // Send null character to indicate end of message
    send_character(server_pid, '\0');

    return (0);
}
