/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:11:32 by sel-kham          #+#    #+#             */
/*   Updated: 2023/05/05 18:53:17 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	default_handler(t_data *data)
{
	if (!(data->event.horizontal_movement || data->event.vertical_movement \
		|| data->event.rotation))
		return (0);
	if (!init_img(data))
		fatal_error(TEXTURE_ERROR);
	events_router(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx->mlx_p, data->mlx->win_p, \
		data->mlx->img.img, 0, 0);
	mlx_destroy_image(data->mlx->mlx_p, data->mlx->img.img);
	return (0);
}

int	keydown_handler(int keycode, t_data *data)
{
	if (keycode == A_KEY)
		data->event.horizontal_movement = -1;
	if (keycode == D_KEY)
		data->event.horizontal_movement = 1;
	if (keycode == W_KEY)
		data->event.vertical_movement = -1;
	if (keycode == S_KEY)
		data->event.vertical_movement = 1;
	if (keycode == LA_KEY)
		data->event.rotation = -1;
	if (keycode == RA_KEY)
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
	if (data->event.keycode == ESC_KEY)
		destroy_event(data);
	data->event.keycode = keycode;
	return (EXIT_SUCCESS);
}

int	events_router(t_data *data)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	events_router1(data, &x, &y);
	events_router2(data, &x, &y);
	events_router3(data);
	if (data->maze->map[(int) y][(int) x] == AREA)
	{
		if (data->maze->map[(int) y][(int) data->player->position.x] \
			!= WALL && data->maze->map[(int) \
				data->player->position.y][(int) x] != WALL)
		{
			data->player->position.x = x;
			data->player->position.y = y;
		}
	}
	return (0);
}

int	destroy_event(t_data *data)
{
	int	i;

	i = -1;
	if (!data)
		return (EXIT_SUCCESS);
	while (++i < 4)
		mlx_destroy_image(data->mlx->mlx_p, data->textures[i].img.img);
	free_mlx(data->mlx);
	free_maze(data->maze);
	free(data->player);
	free(data);
	data = NULL;
	exit(EXIT_SUCCESS);
}
