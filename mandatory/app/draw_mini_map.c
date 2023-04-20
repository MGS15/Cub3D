/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:33:12 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/20 05:56:33 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_vector	get_change_in_sqr(t_data *data, t_ray ray)
{
	t_vector	vec;

	if (ray.ray_v.x > 0.0)
		vec.x = ray.change.x * ((double) ray.map_x + 1.0 - data->player->position.x);
	else
		vec.x = ray.change.x * (data->player->position.x - (double) ray.map_x);
	if (ray.ray_v.y > 0)
		vec.y = ray.change.y * ((double) ray.map_y + 1.0 - data->player->position.y);
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
		ray->change_in_sqr.y -= ray->change.y;
	if (ray->interction == 0)
		ray->change_in_sqr.x -= ray->change.x;
}

void	draw_player(t_data *data)
{
	t_ray	ray;
	double	camera;
	int x;

	x = -1;
	while (++x <  WINDOW_WIDTH)
	{
		ft_bzero(&ray, sizeof(t_ray));
		camera = 2.0 * (x / (double) WINDOW_WIDTH) - 1;
		ray.ray_v.x = data->player->plane.x * camera + data->player->direction.x;
		ray.ray_v.y = data->player->plane.y * camera + data->player->direction.y;
		ray.change.x = 1 / fabs(ray.ray_v.x);
		ray.change.y = 1 / fabs(ray.ray_v.y);
		ray.map_x = (int) data->player->position.x;
		ray.map_y = (int) data->player->position.y;
		get_map_increament(&ray);
		ray.change_in_sqr = get_change_in_sqr(data, ray);
		get_ray_length(&ray, data->maze->map);
		if (ray.interction == 0)
			ray.wall_height = (double) WINDOW_HEIGHT / ray.change_in_sqr.x;

		else if (ray.interction == 1)
			ray.wall_height = (double) WINDOW_HEIGHT / ray.change_in_sqr.y;
		
		
		
		if (ray.interction == 0)
		{
			ray.intersection_x = data->player->position.y + ray.change_in_sqr.x * ray.ray_v.y;
			// printf("XXX :%f | %f | %f | %f\n", ray.intersection_x, data->player->position.x, ray.change_in_sqr.x, ray.ray_v.x); TODO: Handle textures here
		}
		else if (ray.interction == 1)
		{
			ray.intersection_x = data->player->position.x + ray.change_in_sqr.y * ray.ray_v.x;
			// printf("YYY :%f | %f | %f | %f\n", ray.intersection_x, data->player->position.y, ray.change_in_sqr.y, ray.ray_v.y);  TODO: Handle textures here
		}
		// printf("%f\n", ray.intersection_x);
		ray.draw_start = -ray.wall_height / 2 + WINDOW_HEIGHT / 2;
		ray.draw_end = ray.wall_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_start < 0)
				ray.draw_start = 0;
		if (ray.draw_end >= WINDOW_HEIGHT)
			ray.draw_end = WINDOW_HEIGHT - 1;
		ray.draw_start--;
		while (++ray.draw_start < ray.draw_end)
			my_mlx_pixle_put(&data->mlx->img, set_coords(x, ray.draw_start), 0xFF00FF);
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT && data->maze->map[i / BLOCK_UNIT])
	{
		j = 0;
		while (j < WINDOW_WIDTH && data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT])
		{
			if (data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT] == WALL)
				draw_block(data, j, i, BLOCK_UNIT - 1, 0x00FFFF);
			else if (data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT] == AREA \
				|| is_spawning_position(data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT]))
				draw_block(data, j, i, BLOCK_UNIT - 1, 0xF1F1F1);
			j += BLOCK_UNIT;
		}
		i += BLOCK_UNIT;
	}
}
