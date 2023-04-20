/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:11:32 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/20 06:18:52 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	default_handler(t_data *data)
{
	init_img(data);
	events_router(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx->mlx_p, data->mlx->win_p, data->mlx->img.img,0, 0);
	mlx_destroy_image(data->mlx->mlx_p, data->mlx->img.img);
	return (0);
}

int	keydown_handler(int keycode, t_data *data)
{
	if (keycode == A_KEY)
		data->event.horizontal_movement = -1;
	else if (keycode == D_KEY)
		data->event.horizontal_movement = 1;
	else if (keycode == W_KEY)
		data->event.vertical_movement = -1;
	else if (keycode == S_KEY)
		data->event.vertical_movement = 1;
	else if (keycode == LA_KEY)
		data->event.rotation = -1;
	else if (keycode == RA_KEY)
		data->event.rotation = 1;
	data->event.keycode = keycode;
	return (EXIT_SUCCESS);
}

int	keyup_handler(int keycode, t_data *data)
{
	if (keycode == A_KEY)
		data->event.horizontal_movement = 0;
	else if (keycode == D_KEY)
		data->event.horizontal_movement = 0;
	else if (keycode == W_KEY)
		data->event.vertical_movement = 0;
	else if (keycode == S_KEY)
		data->event.vertical_movement = 0;
	else if (keycode == LA_KEY)
		data->event.rotation = 0;
	else if (keycode == RA_KEY)
		data->event.rotation = 0;
	data->event.keycode = keycode;
	return (EXIT_SUCCESS);
}

int	events_router(t_data *data)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	if (data->event.keycode == A_KEY && data->event.horizontal_movement)
	{
		x = data->player->position.x - (data->player->plane.x * data->player->walk_speed);
		y = data->player->position.y - (data->player->plane.y * data->player->walk_speed);
	}
	else if (data->event.keycode == S_KEY && data->event.vertical_movement)
	{
		x = data->player->position.x -(data->player->direction.x * data->player->walk_speed);
		y = data->player->position.y -(data->player->direction.y * data->player->walk_speed);
	}
	else if (data->event.keycode == D_KEY && data->event.horizontal_movement)
	{
		x = data->player->position.x + (data->player->plane.x * data->player->walk_speed);
		y = data->player->position.y + (data->player->plane.y * data->player->walk_speed);
	}
	else if (data->event.keycode == W_KEY && data->event.vertical_movement)
	{
		x = data->player->position.x + data->player->direction.x * data->player->walk_speed;
		y = data->player->position.y + data->player->direction.y * data->player->walk_speed;
	}
	else if (data->event.keycode == RA_KEY && data->event.rotation)
	{
		data->player->direction = set_vector(data->player->direction.x * cos(ROT_L) - data->player->direction.y * sin(ROT_L), \
			data->player->direction.x * sin(ROT_L) + cos(ROT_L) * data->player->direction.y);
		data->player->plane = set_vector(data->player->plane.x * cos(ROT_L) - data->player->plane.y * sin(ROT_L), \
			data->player->plane.x * sin(ROT_L) + cos(ROT_L) * data->player->plane.y);
	}
	else if (data->event.keycode == LA_KEY && data->event.rotation)
	{
		data->player->direction = set_vector(data->player->direction.x * cos(ROT_R) - data->player->direction.y * sin(ROT_R), \
			data->player->direction.x * sin(ROT_R) + cos(ROT_R) * data->player->direction.y);
		data->player->plane = set_vector(data->player->plane.x * cos(ROT_R) - data->player->plane.y * sin(ROT_R), \
			data->player->plane.x * sin(ROT_R) + cos(ROT_R) * data->player->plane.y);
	}
	else if (data->event.keycode == ESC_KEY)
		destroy_event(data);
	if (data->maze->map[(int) y][(int) x] == AREA)
	{
		data->player->position.x = x;
		data->player->position.y = y;
	}
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
