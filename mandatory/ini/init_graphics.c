/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:54:31 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/17 22:14:30 by sel-kham         ###   ########.fr       */
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
	mlx->img.img = mlx_new_image(mlx->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->img.img)
		return (0);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
		 &mlx->img.line_len, &mlx->img.endian);
	return (mlx);
}

t_player	*init_player(void)
{
	t_player	*player;
	
	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->position.x = -1;
	player->position.y = -1;
	player->radius = -1;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = 0.0;
	player->move_speed = 0.0;
	player->rotation_speed = 0.0;
	return (player);
}
