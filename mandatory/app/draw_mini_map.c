/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:33:12 by sel-kham          #+#    #+#             */
/*   Updated: 2023/05/02 16:58:49 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_vector	get_change_in_sqr(t_data *data, t_ray ray)
{
	t_vector	vec;

	if (ray.ray_v.x > 0.0)
		vec.x = ray.change.x * ((double) ray.map_x \
			+ 1.0 - data->player->position.x);
	else
		vec.x = ray.change.x * (data->player->position.x - (double) ray.map_x);
	if (ray.ray_v.y > 0)
		vec.y = ray.change.y * ((double) ray.map_y + \
			1.0 - data->player->position.y);
	else
		vec.y = ray.change.y * (data->player->position.y - (double) ray.map_y);
	return (vec);
}

void	get_map_increament(t_ray *ray)
{
	if (ray->ray_v.x > 0)
		ray->inc_x = 1;
	else
		ray->inc_x = -1;
	if (ray->ray_v.y > 0)
		ray->inc_y = 1;
	else
		ray->inc_y = -1;
}

void	get_ray_length(t_ray *ray, char **map)
{
	int	stp;

	stp = 1;
	while (stp)
	{
		if (ray->change_in_sqr.x < ray->change_in_sqr.y)
		{
			ray->change_in_sqr.x += ray->change.x;
			ray->map_x += ray->inc_x;
			ray->interction = 0;
		}
		else
		{
			ray->change_in_sqr.y += ray->change.y;
			ray->map_y += ray->inc_y;
			ray->interction = 1;
		}
		if (map[ray->map_y][ray->map_x] != AREA)
			stp = 0;
	}
	if (ray->interction == 1)
		ray->perp = ray->change_in_sqr.y - ray->change.y;
	if (ray->interction == 0)
		ray->perp = ray->change_in_sqr.x - ray->change.x;
}

int	get_polarity(t_ray ray)
{
	if (ray.interction == 0 && ray.ray_v.x <= 0)
		return (1);
	else if (ray.interction == 0 && ray.ray_v.x > 0)
		return (2);
	else if (ray.interction == 1 && ray.ray_v.y > 0)
		return (3);
	else if (ray.interction == 1 && ray.ray_v.y <= 0)
		return (0);
	return (-1);
}

void	get_x_pos(t_data *data, t_ray *ray)
{
	ray->wall_height = WINDOW_HEIGHT / ray->perp;
	if (ray->interction == 0)
		ray->intersection_x = data->player->position.y \
			+ ray->perp * ray->ray_v.y;
	else if (ray->interction == 1)
		ray->intersection_x = data->player->position.x \
			+ ray->perp * ray->ray_v.x;
	ray->intersection_x -= (int)ray->intersection_x;
	ray->texture_intersection = ray->intersection_x \
		* data->textures[get_polarity(*ray)].width;
}
