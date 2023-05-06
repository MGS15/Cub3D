/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:22:47 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/06 16:59:10 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

static int	check_rgb(char *rgb)
{
	int	i;
	int	comma;

	i = -1;
	comma = 0;
	while (rgb[++i])
		if (rgb[i] == ',')
			comma++;
	i = -1;
	while (rgb[++i] && ft_isspace(rgb[i]))
		;
	if (!i || comma != 2)
		return (-2);
	return (i);
}

t_rgb	*rgb_parser(char *rgb)
{
	t_rgb	*rgbp;
	char	**rgb_array;
	int		i;

	i = check_rgb(rgb);
	if (i == -2)
		return (NULL);
	rgb_array = ft_split(rgb + i, ',');
	if (!rgb_array)
		return (print_error(MEMORY_ERROR), NULL);
	if (double_pointer_len((void **) rgb_array) != 3)
		return (free_double_pointer((void **) rgb_array), \
			print_error(MAP_PARSE_ERROR), NULL);
	i = -1;
	rgbp = init_rgb();
	if (!rgbp)
		return (print_error(MEMORY_ERROR), NULL);
	while (rgb_array[++i])
		if (!ft_isnumeric(rgb_array[i]) \
			|| ft_atoi(rgb_array[i]) < 0 || ft_atoi(rgb_array[i]) > 255)
			return (free_double_pointer((void **) rgb_array), free(rgbp), \
				print_error(MAP_PARSE_ERROR), NULL);
	*rgbp = set_rgb(ft_atoi(rgb_array[0]), ft_atoi(rgb_array[1]), \
		ft_atoi(rgb_array[2]));
	return (free_double_pointer((void **) rgb_array), rgbp);
}

char	*texture_parser(char *texture)
{
	int	i;

	i = -1;
	while (texture[++i] && ft_isspace(texture[i]))
		;
	if (!i)
		return (NULL);
	if (!extention_checker(texture + i, ".xpm"))
		return (NULL);
	return (ft_strdup(texture + i));
}

static int	config_parser2(t_maze **maze, char *trimmed_line)
{
	if (trimmed_line[0] == 'E' && trimmed_line[1] == 'A'\
		&& !(*maze)->east_side)
	{
		(*maze)->east_side = texture_parser(trimmed_line + 2);
		return (1);
	}
	else if (trimmed_line[0] == 'W' && trimmed_line[1] == 'E'\
		&& !(*maze)->west_side)
	{
		(*maze)->west_side = texture_parser(trimmed_line + 2);
		return (1);
	}
	else if (trimmed_line[0] == 'F' && trimmed_line[1])
	{
		(*maze)->floor = rgb_parser(trimmed_line + 1);
		return (1);
	}
	else if (trimmed_line[0] == 'C' && trimmed_line[1])
	{
		(*maze)->ceilling = rgb_parser(trimmed_line + 1);
		return (1);
	}
	return (0);
}

int	config_parser(t_maze **maze, char *line)
{
	char	*trimmed_line;

	if (!line[0] || line[0] == NEWLINE || ft_isblank(line))
		return (0);
	trimmed_line = ft_strtrim(line, WHITESPACES);
	if (!trimmed_line)
		return (-1);
	if (config_parser2(maze, trimmed_line))
		return (free(trimmed_line), 1);
	if (trimmed_line[0] == 'N' && trimmed_line[1] == 'O'\
		&& !(*maze)->north_side)
		(*maze)->north_side = texture_parser(trimmed_line + 2);
	else if (trimmed_line[0] == 'S' && trimmed_line[1] == 'O'\
		&& !(*maze)->south_side)
		(*maze)->south_side = texture_parser(trimmed_line + 2);
	else
		return (free(trimmed_line), -1);
	return (free(trimmed_line), 1);
}
