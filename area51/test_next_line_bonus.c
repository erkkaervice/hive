/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_next_line_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:02:39 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 14:57:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	open_file(const char *f)
{
	int	fd;

	fd = open(f, O_RDONLY);
	return (fd);
}

void	open_files_recursively(int *fd, char **fs, int i, int pax)
{
	if (i < pax)
	{
		fd[i] = open_file(fs[i]);
		open_files_recursively(fd, fs, i + 1, pax);
	}
}

void	read_files_recursively(int *fd, int i, int fc, int *on)
{
	char	*line;

	if (*on == 0)
		return ;

	if (fd[i] != -1)
	{
		line = get_next_line(fd[i]);
		if (line)
		{
			printf("File %d: %s\n", i + 1, line);
			free(line);
		}
		else
		{
			close(fd[i]);
			fd[i] = -1;
			(*on)--;
		}
	}
	i = (i + 1) % fc;
	read_files_recursively(fd, i, fc, on);
}

int	main(int argc, char **argv)
{
	int	*fd;
	int	af;

	fd = (int *)malloc(sizeof(int) * (argc - 1));
	open_files_recursively(fd, argv + 1, 0, argc - 1);
	af = argc - 1;
	read_files_recursively(fd, 0, argc - 1, &af);
	free(fd);
	return (EXIT_SUCCESS);
}
