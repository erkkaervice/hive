/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:19:49 by eala-lah          #+#    #+#             */
/*   Updated: 2024/01/31 21:10:23 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**data;
}	t_map;

int		read_map_file(const char *filename, t_map *map);
void	process_maps(int argc, char **argv);
void	find_biggest_square(t_map *map);
int		validate_map(t_map *map);
void	print_map(t_map *map);
void	free_memory(t_map *map);

int	main(int argc, char **argv)
{
	process_maps(argc, argv);
	return (0);
}

int	read_map_file(const char *filename, t_map *map)
{
	int	fd = open(filename, O_RDONLY);

	if (fd < 0)
	{
		write(2, "Error: Could not open file\n", 28);
		return (0);
	}
	// Implement the logic to read a map file
	// ...
	close(fd);
	return (1);
}

void	process_maps(int argc, char **argv)
{
	int	i = 1;

	while (i < argc)
	{
		t_map	map;
		if (read_map_file(argv[i], &map))
		{
			if (validate_map(&map))
			{
				find_biggest_square(&map);
				print_map(&map);
				free_memory(&map);
			}
			else
			{
				write(2, "map error\n", 11);
			}
		}
		else
		{
			write(2, "Error: Could not read map file\n", 32);
		}
		i++;
	}
}

void	find_biggest_square(t_map *map)
{
	// Implement the logic to find the largest square
	// ...
}

int	validate_map(t_map *map)
{
	// Implement the logic to validate a map
	// ...
	return (1);
}

void	print_map(t_map *map)
{
	int	i = 0;

	while (i < map->rows)
	{
		write(1, map->data[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
}

void	free_memory(t_map *map)
{
	int	i = 0;

	while (i < map->rows)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}
