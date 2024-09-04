/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:43 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/04 13:13:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t g_response;

void feedback_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        g_response = 1;
    }
}

void wait_for_feedback(int is_end, int bit)
{
    while (g_response == 0)
    {
        pause();  // Wait for acknowledgment
    }
    if (is_end && (bit == 0))
    {
        ft_printf("Received\n");
    }
    g_response = 0;  // Reset response flag
}

void ctob(int server_pid, char c, int is_end)
{
    int bit;
    struct sigaction sa;

    bit = 7;
    g_response = 0;

    // Set up signal handler for feedback
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = feedback_handler;

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_error("ERROR IN SETTING UP SIGNAL HANDLER");
    }

    // Send each bit of the character
    while (bit >= 0)
    {
        if ((c & (1 << bit)) != 0)
        {
            if (kill(server_pid, SIGUSR1) == -1)
            {
                ft_error("ERROR IN SENDING SIGNAL");
            }
        }
        else
        {
            if (kill(server_pid, SIGUSR2) == -1)
            {
                ft_error("ERROR IN SENDING SIGNAL");
            }
        }
        wait_for_feedback(is_end, bit);  // Wait for server acknowledgment
        bit--;
    }
}

int main(int argc, char **argv)
{
    int server_pid;
    char *msg;

    if (argc != 3 || !(*argv[2]))
    {
        ft_error("ERROR IN INPUTS");
    }
    else
    {
        server_pid = ft_atoi(argv[1]);
        if (server_pid <= 0)
        {
            ft_error("ERROR IN INPUTS");
        }
        msg = argv[2];
    }

    while (*msg)
    {
        ctob(server_pid, *msg, 0);  // Send each character
        msg++;
    }
    ctob(server_pid, *msg, 1);  // Send end-of-message signal

    return 0;
}
