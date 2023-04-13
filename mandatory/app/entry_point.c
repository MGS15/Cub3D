/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:13:40 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/13 02:08:48 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	entry_point(t_maze *maze)
{
	t_data 		data;
	t_mlx		*mlx;
	t_player	*player;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (free_maze(maze), fatal_error(MEMORY_ERROR));
	player = init_player();
	if (!graphic_ini(mlx) || !player)
		return (free_maze(maze), free_mlx(mlx), fatal_error(MEMORY_ERROR));
	*player = set_player(maze);
	minimap_draw(maze, mlx, player->position);
	data.player = player;
	data.mlx = mlx;
	data.maze = maze;
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img, 0, 0);
	mlx_hook(mlx->win_p, ON_DESTROY, 0, destroy_game, (void *) &data);
	mlx_hook(mlx->win_p, ON_KEYDOWN, 0, events_router, (void *) &data);
	mlx_loop(mlx->mlx_p);
}
