/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:22:47 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 21:38:44 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_rgb	*rgb_parser(char *rgb)
{
	t_rgb	*rgbp;
	char	**rgb_array;
	int		i;

	rgb_array = ft_split(rgb, ',');
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
			|| ft_atoi(rgb_array[i]) < 0 || ft_atoi(rgb_array[i]) > 256)
			return (free_double_pointer((void **) rgb_array), free(rgbp), \
				print_error(MAP_PARSE_ERROR), NULL);
	*rgbp = set_rgb(ft_atoi(rgb_array[0]), ft_atoi(rgb_array[1]), \
		ft_atoi(rgb_array[2]));
	return (free_double_pointer((void **) rgb_array), rgbp);
}

char	*texture_parser(char *texture)
{
	if (!extention_checker(texture, ".xpm"))
		return (NULL);
	return (ft_strdup(texture));
}

int	config_parser(t_maze **maze, char *line)
{
	char	*trimmed_line;
	char	**config;

	if (!line[0] || line[0] == NEWLINE)
		return (0);
	trimmed_line = ft_strtrim(line, WHITESPACES);
	if (!trimmed_line)
		return (-1);
	config = ft_split(trimmed_line, ' ');
	if (!config)
		return (free(trimmed_line), -1);
	if (double_pointer_len((void **) config) != 2 \
		|| (ft_strlen(config[0]) != 2 && ft_strlen(config[0]) != 1))
		return (free(trimmed_line), \
			free_double_pointer((void **) config), -1);
	if (config[0][0] == 'N' && config[0][1] == 'O' && !(*maze)->north_side)
		(*maze)->north_side = texture_parser(config[1]);
	else if (config[0][0] == 'S' && config[0][1] == 'O' && !(*maze)->south_side)
		(*maze)->south_side = texture_parser(config[1]);
	else if (config[0][0] == 'E' && config[0][1] == 'A' && !(*maze)->east_side)
		(*maze)->east_side = texture_parser(config[1]);
	else if (config[0][0] == 'W' && config[0][1] == 'E' && !(*maze)->west_side)
		(*maze)->west_side = texture_parser(config[1]);
	else if (config[0][0] == 'F' && !config[0][1])
		(*maze)->floor = rgb_parser(config[1]);
	else if (config[0][0] == 'C' && !config[0][1])
		(*maze)->ceilling = rgb_parser(config[1]);
	else
		return (free_double_pointer((void **) config), \
			free(trimmed_line), -1);
	free_double_pointer((void **) config);
	return (free(trimmed_line), 1);
}
