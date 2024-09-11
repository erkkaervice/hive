/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:08 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/11 14:44:53 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/inc/libft.h"
# include <signal.h>
# include <stdlib.h>

# define MAX_RETRIES 5
# define RETRY_DELAY 1000000

void	ft_signal(int server_pid, int signal);
void	ft_bit(int sig, int *chr, int *bit);

#endif