/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:30:10 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/03 15:51:19 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	texturing_floor_ceiling(t_data *data, t_ray *ray, int x, int flag)
{
	int	j;

	if (!flag)
	{
		j = -1;
		while (++j <= ray->draw_start)
			my_mlx_pixle_put(&data->mlx->img, set_coords(x, j), \
				rgb_to_int(*data->maze->ceilling));
	}
	else
	{
		j = ray->draw_start;
		while (++j < WINDOW_HEIGHT)
			my_mlx_pixle_put(&data->mlx->img, set_coords(x, j), \
				rgb_to_int(*data->maze->floor));
	}
}

void	texturing(t_data *data, t_ray *ray, int x)
{
	double		scale;
	t_texture	*tex;
	int			i;
	int			j;
	int			temp;

	i = 0;
	j = -1;
	scale = (double)data->textures[get_polarity(*ray)].height \
		/ ray->wall_height;
	temp = ray->draw_start - 1;
	ray->draw_start--;
	tex = &data->textures[get_polarity(*ray)];
	texturing_floor_ceiling(data, ray, x, 0);
	if (ray->draw_start == -1)
		i = (ray->wall_height - WINDOW_HEIGHT) / 2;
	while (++ray->draw_start < ray->draw_end)
	{
		my_mlx_pixle_put(&data->mlx->img, set_coords(x, ray->draw_start), \
			get_pixel(tex, ray->texture_intersection, i * scale));
		i++;
	}
	texturing_floor_ceiling(data, ray, x, 1);
	ray->draw_start = temp;
}

void	draw_player2(t_data *data, t_ray *ray)
{
	ray->map_x = (int) data->player->position.x;
	ray->map_y = (int) data->player->position.y;
	get_map_increament(ray);
	ray->change_in_sqr = get_change_in_sqr(data, *ray);
	get_ray_length(ray, data->maze->map);
	get_x_pos(data, ray);
	ray->draw_start = -ray->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
}

void	draw_player(t_data *data)
{
	t_ray	ray;
	double	camera;
	int		x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		ft_bzero(&ray, sizeof(t_ray));
		camera = 2.0 * (x / (double) WINDOW_WIDTH) - 1;
		ray.ray_v.x = data->player->plane.x * \
			camera + data->player->direction.x;
		ray.ray_v.y = data->player->plane.y * \
			camera + data->player->direction.y;
		if (ray.ray_v.x)
			ray.delta_dist.x = 1 / fabs(ray.ray_v.x);
		else
			ray.delta_dist.x = 1e30;
		if (ray.ray_v.y)
			ray.delta_dist.y = 1 / fabs(ray.ray_v.y);
		else
			ray.delta_dist.y = 1e30;
		draw_player2(data, &ray);
		texturing(data, &ray, x);
	}
}
