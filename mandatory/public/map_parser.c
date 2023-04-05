/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:33:06 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/05 03:38:26 by sel-kham         ###   ########.fr       */
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

char	**get_map(int fd)
{
	char	*line;
	char	**map;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_isblank(line) || line[0])
			break ;
		printf("%s\n", line);
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

char	**parse_map(int fd)
{
	char	**map;
	char	**new_map;
	size_t	matrix_width;
	int		i;

	map = get_map(fd);
	if (!map)
		return (NULL);
	i = -1;
	matrix_width = martix_len(map);
	new_map = (char **) ft_calloc(sizeof(char *), matrix_width + 1);
	if (!new_map)
		return (free_double_pointer((void **) map), NULL);
	while (map[++i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			return (free_double_pointer((void **) map),
				free_double_pointer((void **) map), NULL);
	}
	// while (new_map[++t])
	// 	printf("%s\n", new_map[t]);
	return (free_double_pointer((void **) map), new_map);
}
