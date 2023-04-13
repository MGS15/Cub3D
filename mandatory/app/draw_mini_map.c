/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:33:12 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/12 05:00:42 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	draw_circle(int radius, t_coords c, t_mlx *mlx)
{
	int	i;
	int	j;
	int	init_x;
	int	init_y;
	int	eq;

	init_x = c.x * BLOCK_UNIT;
	init_y = (c.y * BLOCK_UNIT) - 1;
	c.x = (c.x * BLOCK_UNIT) + BLOCK_UNIT / 2;
	c.y = (c.y * BLOCK_UNIT) + BLOCK_UNIT / 2;
	i = init_y;
	while (++i <= BLOCK_UNIT + init_y)
	{
		j = init_x - 1;
		while (++j <= init_x + BLOCK_UNIT)
		{
			eq = pow(j - c.x , 2) + pow(i - c.y,  2);
			if (eq <= pow(radius, 2))
				my_mlx_pixle_put(&mlx->img, set_coords(j, i), 0x00FFFF);
			else
				my_mlx_pixle_put(&mlx->img, set_coords(j, i), 0xCFCFCF);
		}
		
	}
}

void	print_block(t_img *img, t_coords coord, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < BLOCK_UNIT)
	{
		j = -1;
		while (++j < BLOCK_UNIT)
			my_mlx_pixle_put(img, set_coords(j + coord.x * BLOCK_UNIT, i + coord.y * BLOCK_UNIT), color);
	}
}

void	minimap_draw(t_maze *maze, t_mlx *mlx, t_coords p)
{
	int	i;
	int	j;

	i = -1;
	while (maze->map[++i] && i < WINDOW_HEIGHT)
	{
		j = -1;
		while (maze->map[i][++j] && j < WINDOW_WIDTH)
		{
			if (maze->map[i][j] == WALL)
				print_block(&mlx->img, set_coords(j, i), 0xFF00FF);
			else if (maze->map[i][j] == AREA)
				print_block(&mlx->img, set_coords(j, i), 0xCFCFCF);
			else if (is_spawning_position(maze->map[i][j]))
				draw_circle(PLAYER_RADIUS, p, mlx);
		}
	}
}
