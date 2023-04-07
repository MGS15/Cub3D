/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:13:43 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/07 20:33:36 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3D.h"

// static void	print_maze(t_maze *maze)
// {
// 	int	i;

// 	i = -1;
// 	printf("NORTH SIDE: %s\n", maze->north_side);
// 	printf("SOUTH SIDE: %s\n", maze->south_side);
// 	printf("EAST SIDE: %s\n", maze->east_side);
// 	printf("WEST SIDE: %s\n", maze->west_side);
// 	printf("FLOOR: %d, %d, %d\n", maze->floor->r, maze->floor->g, \
// 		maze->floor->b);
// 	printf("CEILLING: %d, %d, %d\n", maze->floor->r, maze->floor->g, \
// 		maze->floor->b);
// 	while (maze->map[++i])
// 		printf("%s\n", maze->map[i]);
// }

static t_maze	*map_checker(int fd)
{
	t_maze	*maze;

	maze = get_maze(fd);
	if (!maze)
		return (NULL);
	if (!maze->north_side || !maze->south_side || !maze->east_side \
		|| !maze->west_side ||!maze->ceilling || !maze->floor || !maze->map)
		return (free_maze(maze), print_error(MAP_PARSE_ERROR), NULL);
	return (maze);
}

int	main(int c, char **v)
{
	t_maze	*maze;
	int		fd;

	if (c != 2)
		fatal_error(ARGS_ERROR);
	if (v[1] && v[1][0])
		if (!extention_checker(v[1], ".cub"))
			fatal_error(ARGUMENTS_ERROR);
	fd = open(v[1], O_RDONLY);
	if (fd < 0)
		fatal_error(MAP_FILE_ERROR);
	maze = map_checker(fd);
	if (!maze)
		return (EXIT_FAILURE);
	if (!is_valid_map(maze))
		return (free_maze(maze), print_error(MAP_PARSE_ERROR), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
