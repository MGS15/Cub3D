/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:05:03 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/17 21:52:16 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	my_mlx_pixle_put(t_img *img, t_coords coord, int color)
{
	char	*dst;

	dst = img->addr + (coord.y * img->line_len + coord.x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}
