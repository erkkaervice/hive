/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:27 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/19 15:12:25 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_col
{
	int		val;
	int		ind;
	int		pos;
	int		tar;
	int		coa;
	int		cob;
	stuct s_col	*nex;
}	t_col;
