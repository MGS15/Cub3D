/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:33:06 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/06 17:05:15 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

static char	*map_handler(char *first_line, int fd)
{
	char	*line;
	char	*new_line;

	new_line = NULL;
	new_line = ft_strjoin2(new_line, first_line, ft_strlen2(first_line));
	if (!new_line)
		return (print_error(MEMORY_ERROR), free(first_line), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == NEWLINE)
			return (free(line), free(new_line), free(first_line), NULL);
		new_line = ft_strjoin2(new_line, line, ft_strlen2(line));
		free(line);
		line = get_next_line(fd);
	}
	return (free(first_line), new_line);
}

char	**get_map(int fd, char *line)
{
	char	**map;

	while (line)
	{
		if (!ft_isblank(line) || !line[0] || line[0] != NEWLINE)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (line[0] != WALL && line[0] != EMPTY_SPACE)
		return (free(line), NULL);
	line = map_handler(line, fd);
	if (!line)
		return (NULL);
	map = ft_split(line, NEWLINE);
	return (free(line), map);
}

char	**parse_map(int fd, char *line)
{
	char	**map;
	char	**new_map;
	size_t	matrix_height;
	size_t	matrix_width;
	int		i;

	map = get_map(fd, line);
	if (!map)
		return (NULL);
	i = -1;
	matrix_height = martix_len(map);
	matrix_width = get_lognest_line(map);
	new_map = (char **) ft_calloc(sizeof(char *), matrix_height + 1);
	if (!new_map)
		return (free_double_pointer((void **) map), NULL);
	while (map[++i])
	{
		new_map[i] = ft_calloc(sizeof(char), matrix_width + 1);
		if (!new_map[i])
			return (free_double_pointer((void **) map),
				free_double_pointer((void **) map), NULL);
		ft_memcpy(new_map[i], map[i], ft_strlen(map[i]));
	}
	return (free_double_pointer((void **) map), new_map);
}
