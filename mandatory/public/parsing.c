/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:03:51 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/06 16:58:18 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

bool	is_spawning_position(char c)
{
	return (c == SD_E || c == SD_W || c == SD_S || c == SD_N);
}

bool	is_map_element(char c)
{
	return (c == WALL || c == AREA
		|| is_spawning_position(c));
}

bool	is_valid_map(t_maze *maze)
{
	int		i;
	int		j;
	short	p;

	i = -1;
	p = 0;
	while (maze->map[++i])
	{
		j = -1;
		while (maze->map[i][++j])
		{
			if (!check_borders(maze, i, j))
				return (false);
			if (maze->map[i][j] && ft_isspace(maze->map[i][j]))
				continue ;
			else
				if (!check_map_area(maze, i, j, &p))
					return (false);
		}
	}
	if (p != 1)
		return (false);
	return (true);
}

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
	if (results != 6 || !line)
		return (free_maze(maze), NULL);
	maze->map = parse_map(fd, line);
	return (maze);
}
