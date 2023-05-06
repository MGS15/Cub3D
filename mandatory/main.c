/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:13:43 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/06 16:58:04 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3D.h"

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
	entry_point(maze);
	return (EXIT_SUCCESS);
}
