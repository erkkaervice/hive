/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:08 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/29 16:03:27 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/inc/libft.h"
# include <signal.h>
# include <sys/types.h>

typedef struct s_msg
{
	unsigned char	chr;
	int				btc;
}	t_msg;

#endif