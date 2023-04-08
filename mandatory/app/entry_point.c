/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:13:40 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/08 01:43:59 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	entry_point(t_maze *maze)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (free_maze(maze), fatal_error(MEMORY_ERROR));
	if (!graphic_ini(mlx))
		return (free_maze(maze), free_mlx(mlx), fatal_error(MEMORY_ERROR));
	my_mlx_pixle_put(mlx->img.img, maze->player_position, 0x00FF00);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img, 0, 0);
	mlx_loop(mlx->mlx_p);
}
