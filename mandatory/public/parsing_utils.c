/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:11:58 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/02 20:16:04 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	check_borders(t_maze *maze, int i, int j)
{
	maze->map_high = martix_len(maze->map);
	maze->map_width = get_lognest_line(maze->map);
	if (!j && maze->map[i][j] \
			&& maze->map[i][j] != WALL && maze->map[i][j] != ' ')
		return (false);
	if (!i && maze->map[i][j] \
			&& maze->map[i][j] != WALL && !ft_isspace(maze->map[i][j]))
		return (false);
	else if (maze->map[i][j] \
		&& i == (int) maze->map_high - 1 \
		&& maze->map[i][j] != WALL && !ft_isspace(maze->map[i][j]))
		return (false);
	return (true);
}

bool	check_map_area(t_maze *maze, int i, int j, short *p)
{
	if (maze->map[i][j] == AREA \
		|| is_spawning_position(maze->map[i][j]))
	{
		if (!is_map_element(maze->map[i][j - 1]) \
			|| !is_map_element(maze->map[i][j + 1])
			|| !is_map_element(maze->map[i - 1][j])
			|| !is_map_element(maze->map[i + 1][j]))
			return (false);
		if (is_spawning_position(maze->map[i][j]))
		{
			maze->player_position = set_coords(j, i);
			(*p)++;
		}
	}
	else if (!is_map_element(maze->map[i][j]) \
		&& maze->map[i][j] != ' ')
		return (false);
	return (true);
}
