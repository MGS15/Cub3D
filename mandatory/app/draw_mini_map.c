/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:33:12 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/09 01:39:16 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

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

void	print_player(t_img *img, t_coords coord, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < BLOCK_UNIT)
	{
		j = -1;
		while (++j < BLOCK_UNIT)
		{
			if (i == BLOCK_UNIT / 2 && j == BLOCK_UNIT / 2)
				my_mlx_pixle_put(img, set_coords(j + coord.x * BLOCK_UNIT, i + coord.y * BLOCK_UNIT), 0xFFFF00);
			else
				my_mlx_pixle_put(img, set_coords(j + coord.x * BLOCK_UNIT , i + coord.y * BLOCK_UNIT), color);
		}
	}
}

void	minimap_draw(t_maze *maze, t_mlx *mlx)
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
				print_disc(&mlx->img, set_coords(j, i), 0xCFCFCF);
				// print_player(&mlx->img, set_coords(j, i), 0xCFCFCF);
		}
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img, 0, 0);
}
