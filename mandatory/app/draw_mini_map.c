/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:33:12 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/17 22:44:28 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

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
