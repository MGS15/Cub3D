/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:13:40 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/08 02:43:05 by sel-kham         ###   ########.fr       */
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
	minimap_draw(maze, mlx);
	mlx_loop(mlx->mlx_p);
}
