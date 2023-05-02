/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:54:31 by sel-kham          #+#    #+#             */
/*   Updated: 2023/05/02 17:36:08 by aechafii         ###   ########.fr       */
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
	mlx->win_p = mlx_new_window(mlx->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT, \
	"Cub3D");
	if (!mlx->win_p)
		return (0);
	return (mlx);
}

static void	check_east_south(t_maze *maze, t_player *player)
{
	if (maze->map[(int) maze->player_position.y][(int) \
		maze->player_position.x] == SD_E)
	{
		player->direction = set_vector(1, 0);
		player->plane = set_vector(0, -.66);
	}
	else if (maze->map[(int) maze->player_position.y][(int) \
		maze->player_position.x] == SD_S)
	{
		player->direction = set_vector(0, 1);
		player->plane = set_vector(.66, 0);
	}
}

t_player	*init_player(t_maze *maze)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->position.x = maze->player_position.x + 0.5;
	player->position.y = maze->player_position.y + 0.5;
	player->radius = PLAYER_RADIUS;
	if (maze->map[(int) maze->player_position.y][(int) \
		maze->player_position.x] == SD_N)
	{
		player->direction = set_vector(0, -1);
		player->plane = set_vector(-.66, 0);
	}
	else if (maze->map[(int) maze->player_position.y][(int) \
		maze->player_position.x] == SD_W)
	{
		player->direction = set_vector(-1, 0);
		player->plane = set_vector(0, .66);
	}
	check_east_south(maze, player);
	player->rotation_speed = 2 * (M_PI / 180);
	player->walk_speed = .1;
	return (player);
}
