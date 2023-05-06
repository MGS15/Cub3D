/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:05:03 by sel-kham          #+#    #+#             */
/*   Updated: 2023/05/06 16:53:53 by aechafii         ###   ########.fr       */
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
