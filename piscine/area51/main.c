/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:33:51 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/31 12:06:45 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

void				ft_show_tab(struct s_stock_str *par);
struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(int argc, char **argv)
{
	struct s_stock_str	*mission = ft_strs_to_tab(argc - 1, argv + 1);

	if (argc < 2)
	{
		printf("Arguing with an idiot...\n");
		return (1);
	}
	if (mission == 0)
	{
		printf("Mission failed\n");
		return (1);
	}
	ft_show_tab(mission);
	free(mission);
	return (0);
}
