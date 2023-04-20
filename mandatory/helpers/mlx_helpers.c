/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:05:03 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/20 02:58:17 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	my_mlx_pixle_put(t_img *img, t_coords coord, int color)
{
	char	*dst;

	dst = img->addr + ((int) coord.y * img->line_len + (int) coord.x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_circle(t_data *data, int center_x, int center_y, int radius, int color)
{
	int			i;
	int			j;
	int			res;

	i = center_y - radius - 1;
	while (++i < WINDOW_HEIGHT && i < center_y + radius)
	{
		j = center_x - radius - 1;
		while (++j < WINDOW_WIDTH && j < center_x + radius)
		{
			res = pow(j - center_x, 2) + pow(i - center_y, 2);
			if (res <= pow(radius, 2))
				my_mlx_pixle_put(&data->mlx->img, set_coords(j, i), color);
		}
	}
}

void	draw_block(t_data *data, int start_x, int start_y, int side_len, int color)
{
	int	i;
	int	j;

	i = start_y - 1;
	while (++i < side_len + start_y && i < WINDOW_HEIGHT)
	{
		j = start_x - 1;
		while (++j < side_len + start_x && j < WINDOW_WIDTH)
			my_mlx_pixle_put(&data->mlx->img, set_coords(j, i), color);
	}
}

void	draw_line(t_data *data, double len, t_vector vec, int color)
{
	double	x;
	double	y;

	x = data->player->position.x * BLOCK_UNIT + BLOCK_UNIT / 2;
	y = data->player->position.y * BLOCK_UNIT + BLOCK_UNIT / 2;
	while (--len >= 0)
	{
	// printf("len: %f\n", len);
	// color = 0;
		my_mlx_pixle_put(&data->mlx->img, set_coords(round(x), round(y)), color);
		x += vec.x;
		y += vec.y;
	}
}
