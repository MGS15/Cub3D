/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:05:03 by sel-kham          #+#    #+#             */
/*   Updated: 2023/05/02 17:11:40 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	my_mlx_pixle_put(t_img *img, t_coords coord, int color)
{
	char	*dst;

	dst = img->addr + ((int) coord.y * img->line_len \
		+ (int) coord.x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

int	get_pixel(t_texture *texture, int x, int y)
{
	char	*pixle;

	pixle = texture->img.addr + \
		(y * texture->img.line_len + x * (texture->img.bpp / 8));
	return (*(unsigned int *)pixle);
}

void	draw_line(t_data *data, double len, t_vector vec, int color)
{
	double	x;
	double	y;

	x = data->player->position.x * BLOCK_UNIT + BLOCK_UNIT / 2;
	y = data->player->position.y * BLOCK_UNIT + BLOCK_UNIT / 2;
	while (--len >= 0)
	{
		my_mlx_pixle_put(&data->mlx->img, \
			set_coords(round(x), round(y)), color);
		x += vec.x;
		y += vec.y;
	}
}
