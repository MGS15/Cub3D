/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:33:12 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/26 00:14:42 by sel-kham         ###   ########.fr       */
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
		ray->perp = ray->change_in_sqr.y - ray->change.y;
	if (ray->interction == 0)
		ray->perp = ray->change_in_sqr.x - ray->change.x;
}

int	get_polarity(t_ray ray)
{
	if (ray.interction == 0 && ray.ray_v.x  <= 0)
		return 1;
	else if (ray.interction == 0 && ray.ray_v.x >  0)
		return 2;
	else if (ray.interction == 1 && ray.ray_v.y >  0)
		return 3;
	else if (ray.interction == 1 && ray.ray_v.y <=  0)
		return 0;
	return (-1);
}

// unsigned int	get_pixle(t_data *data, t_ray ray, int intersection_x, int intersection_y)
// {
// 	void	*pixle;
// 	int		polarity;
// 	unsigned int	pixle_color;

// 	polarity = get_polarity(ray);
// 	pixle = mlx_get_data_addr(data->textures[polarity].img.img, &data->mlx->img.bpp,&data->mlx->img.line_len, &data->mlx->img.endian);
// 	pixle_color = ((unsigned int *) pixle)[intersection_x * data->mlx->img.line_len / 4 + intersection_y];
// 	return (pixle_color);
// }



// get_x_pos
void	get_x_pos(t_data *data, t_ray *ray)
{
	ray->wall_height =  WINDOW_HEIGHT / ray->perp;
	if (ray->interction == 0)
		ray->intersection_x = data->player->position.y + ray->perp * ray->ray_v.y;
	else if (ray->interction == 1)
		ray->intersection_x = data->player->position.x + ray->perp * ray->ray_v.x;
	ray->intersection_x -= (int)ray->intersection_x;
	ray->texture_intersection = ray->intersection_x * data->textures[get_polarity(*ray)].width;
}

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	texturing(t_data *data, t_ray *ray, int x)
{
	double scale;
	t_texture	*tex;
	int i;


	i = 0;
	int temp;
	scale =  (double)data->textures[get_polarity(*ray)].height / ray->wall_height;
	temp = ray->draw_start - 1;
	ray->draw_start--;
	tex = &data->textures[get_polarity(*ray)];
	
	if (ray->draw_start  == -1)
	{
		i = (ray->wall_height - WINDOW_HEIGHT) / 2;
	}

	while (++ray->draw_start < ray->draw_end)
	{
		// my_mlx_pixle_put(&data->mlx->img, set_coords(x, ray->draw_start), get_pixel(tex, ray->texture_intersection, i * scale));
		pixel_put(&data->mlx->img, x, ray->draw_start , get_pixel(tex, ray->texture_intersection, i * scale));
		i++;
	}
	ray->draw_start = temp;
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
		if (ray.ray_v.x)
			ray.change.x = 1 / fabs(ray.ray_v.x);
		else
			ray.change.x = 1e30;
		if (ray.ray_v.y)
			ray.change.y = 1 / fabs(ray.ray_v.y);
		else
			ray.change.y = 1e30;
		ray.map_x = (int) data->player->position.x;
		ray.map_y = (int) data->player->position.y;
		get_map_increament(&ray);
		ray.change_in_sqr = get_change_in_sqr(data, ray);
		get_ray_length(&ray, data->maze->map);
		get_x_pos(data, &ray);
		ray.draw_start = -ray.wall_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.wall_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_end >= WINDOW_HEIGHT)
			ray.draw_end = WINDOW_HEIGHT - 1;
		
		texturing(data, &ray, x);
	}
}

// void	draw_map(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WINDOW_HEIGHT && data->maze->map[i / BLOCK_UNIT])
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH && data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT])
// 		{
// 			if (data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT] == WALL)
// 				draw_block(data, j, i, BLOCK_UNIT - 1, 0x00FFFF);
// 			else if (data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT] == AREA \
// 				|| is_spawning_position(data->maze->map[i / BLOCK_UNIT][j / BLOCK_UNIT]))
// 				draw_block(data, j, i, BLOCK_UNIT - 1, 0xF1F1F1);
// 			j += BLOCK_UNIT;
// 		}
// 		i += BLOCK_UNIT;
// 	}
// }
