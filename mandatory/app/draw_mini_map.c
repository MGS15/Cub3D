/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:33:12 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/18 21:29:30 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = data->player->position.x * BLOCK_UNIT + BLOCK_UNIT / 2;
	y = data->player->position.y * BLOCK_UNIT + BLOCK_UNIT / 2;
	draw_circle(data, x, y, PLAYER_RADIUS, 0xFF00FF);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT && data->maze->map[i / BLOCK_UNIT])
	{
		j = 0;
		while (j < WINDOW_WIDTH && data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT])
		{
			if (data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT] == WALL)
				draw_block(data, j, i, BLOCK_UNIT - 1, 0x00FFFF);
			else if (data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT] == AREA \
				|| is_spawning_position(data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT]))
				draw_block(data, j, i, BLOCK_UNIT - 1, 0xF1F1F1);
			j += BLOCK_UNIT;
		}
		i += BLOCK_UNIT;
	}
}
