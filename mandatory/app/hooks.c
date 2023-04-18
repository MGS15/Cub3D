/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:11:32 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/18 23:35:12 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	default_handler(t_data *data)
{
	init_img(data);
	draw_map(data);
	draw_circle(data, data->player->position.x, data->player->position.y, PLAYER_RADIUS, 0xFF00FF);
	mlx_put_image_to_window(data->mlx->mlx_p, data->mlx->win_p, data->mlx->img.img,0, 0);
	mlx_destroy_image(data->mlx->mlx_p, data->mlx->img.img);
	return (0);
}

int	events_router(int keycode, t_data *data)
{
	if (keycode == A_KEY)
		data->player->position.x -= 3;
	else if (keycode == S_KEY)
		data->player->position.y += 3;
	else if (keycode == D_KEY)
		data->player->position.x += 3;
	else if (keycode == W_KEY)
		data->player->position.y -= 3;
	return (0);
}

int	destroy_event(t_data *data)
{
	if (!data)
		return (EXIT_SUCCESS);
	free_mlx(data->mlx);
	free_maze(data->maze);
	free(data->player);
	free(data);
	data = NULL;
	exit(EXIT_SUCCESS);
}
