/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:02:39 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/06 12:35:48 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	open_files_recursively(int *fd, char **files, int index, int count)
{
	if (index < count)
	{
		fd[index] = open_file(files[index]);
		open_files_recursively(fd, files, index + 1, count);
	}
}

void	read_files_recursively(int *fd, int index, int file_count, int *active)
{
	char	*line;

	if (*active == 0)
		return ;

	if (fd[index] != -1)
	{
		line = get_next_line(fd[index]);
		if (line)
		{
			printf("File %d: %s\n", index + 1, line);
			free(line);
		}
		else
		{
			close(fd[index]);
			fd[index] = -1;
			(*active)--;
		}
	}
	index = (index + 1) % file_count;
	read_files_recursively(fd, index, file_count, active);
}

int	main(int argc, char **argv)
{
	int	*fd;
	int	active_files;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename1> <filename2> ...\n", argv[0]);
		return (EXIT_FAILURE);
	}
	fd = (int *)malloc(sizeof(int) * (argc - 1));
	if (!fd)
	{
		perror("Error allocating memory");
		return (EXIT_FAILURE);
	}
	open_files_recursively(fd, argv + 1, 0, argc - 1);
	active_files = argc - 1;
	read_files_recursively(fd, 0, argc - 1, &active_files);
	free(fd);
	return (EXIT_SUCCESS);
}
