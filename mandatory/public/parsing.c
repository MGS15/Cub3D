/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:03:51 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/05 03:24:35 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_maze	*get_maze(int fd)
{
	t_maze	*maze;
	char	*line;
	int		results;
	int		old_res;

	results = 0;
	maze = init_maze();
	if (!maze)
		return (print_error(MEMORY_ERROR), NULL);
	line = get_next_line(fd);
	while (line && results < 6)
	{
		old_res = config_parser(&maze, line);
		free(line);
		if (old_res == -1)
			return (print_error(MAP_PARSE_ERROR), free_maze(maze), NULL);
		results += old_res;
		line = get_next_line(fd);
	}
	free(line);
	if (results != 6)
		return (free_maze(maze), NULL);
	maze->map = parse_map(fd);
	return (maze);
}
