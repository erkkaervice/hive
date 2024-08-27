/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:05 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/27 16:47:13 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/libft.h"
# include <signal.h>
# include <sys/types.h>

# define BUFFER_SIZE 4096

typedef struct	s_msg
{
	unsigned char 	chr;
	int			btc;
	char		buf[BUFFER_SIZE];
	int			bix;
}	t_msg;

#endif