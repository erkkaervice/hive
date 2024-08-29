/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:05 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/29 16:00:21 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/libft.h"
# include <signal.h>
# include <sys/types.h>

# define BUFFER_SIZE 1024

typedef struct s_msg
{
	char	*buf;
	char	chr;
	int		btc;
	int		bix;
}	t_msg;

#endif
