/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:34:27 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/02 12:00:52 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	events_router1(t_data *data, double *x, double *y)
{
	if (data->event.horizontal_movement == -1)
	{
		*x = data->player->position.x - \
			(data->player->plane.x * data->player->walk_speed);
		*y = data->player->position.y - \
			(data->player->plane.y * data->player->walk_speed);
	}
	else if (data->event.vertical_movement == 1)
	{
		*x = data->player->position.x - \
			(data->player->direction.x * data->player->walk_speed);
		*y = data->player->position.y - \
			(data->player->direction.y * data->player->walk_speed);
	}
}

void	events_router2(t_data *data, double *x, double *y)
{
	if (data->event.horizontal_movement == 1)
	{
		*x = data->player->position.x + \
			(data->player->plane.x * data->player->walk_speed);
		*y = data->player->position.y + \
			(data->player->plane.y * data->player->walk_speed);
	}
	else if (data->event.vertical_movement == -1)
	{
		*x = data->player->position.x + \
			data->player->direction.x * data->player->walk_speed;
		*y = data->player->position.y + \
			data->player->direction.y * data->player->walk_speed;
	}
}

void	events_router3(t_data *data)
{
	if (data->event.rotation == 1)
	{
		data->player->direction = set_vector(data->player->direction.x * \
			cos(ROT_L) - data->player->direction.y * sin(ROT_L), \
				data->player->direction.x * sin(ROT_L) + cos(ROT_L) \
					* data->player->direction.y);
		data->player->plane = set_vector(data->player->plane.x * \
			cos(ROT_L) - data->player->plane.y * sin(ROT_L), \
				data->player->plane.x * sin(ROT_L) + cos(ROT_L) \
					* data->player->plane.y);
	}
	else if (data->event.rotation == -1)
	{
		data->player->direction = set_vector(data->player->direction.x * \
			cos(ROT_R) - data->player->direction.y * sin(ROT_R), \
				data->player->direction.x * sin(ROT_R) + cos(ROT_R) \
					* data->player->direction.y);
		data->player->plane = set_vector(data->player->plane.x * \
			cos(ROT_R) - data->player->plane.y * sin(ROT_R), \
			data->player->plane.x * sin(ROT_R) + cos(ROT_R) \
				* data->player->plane.y);
	}
}
