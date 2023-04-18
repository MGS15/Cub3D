/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:54:31 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/18 23:31:29 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_mlx	*graphic_ini(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_p = mlx_init();
	if (!mlx->mlx_p)
		return (0);
	mlx->win_p = mlx_new_window(mlx->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!mlx->win_p)
		return (0);
	return (mlx);
}

t_player	*init_player(t_maze *maze)
{
	t_player	*player;
	
	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->position.x = maze->player_position.x * BLOCK_UNIT + BLOCK_UNIT / 2;
	player->position.y = maze->player_position.y * BLOCK_UNIT + BLOCK_UNIT / 2;
	player->radius = PLAYER_RADIUS;
	player->turn_direction = 0;
	player->walk_direction = 0;
	if (maze->map[maze->player_position.y][maze->player_position.x] == SD_N)
		player->rotation_angle = deg_to_rad(90.0);
	else if (maze->map[player->position.x][player->position.y] == SD_W)
		player->rotation_angle = deg_to_rad(180.0);
	else if (maze->map[player->position.x][player->position.y] == SD_E)
		player->rotation_angle = deg_to_rad(0.0);
	else if (maze->map[player->position.x][player->position.y] == SD_S)
		player->rotation_angle = deg_to_rad(270.0);
	player->move_speed = 2.0;
	player->rotation_speed = 2 * (M_PI / 180);
	return (player);
}
