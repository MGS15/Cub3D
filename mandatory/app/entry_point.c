/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:57:35 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/17 22:40:07 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	entry_point(t_maze *maze)
{
	t_data	*data;

	data = (t_data *) ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	data->maze = maze;
	data->mlx = graphic_ini();
	draw_circle(data, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, PLAYER_RADIUS, 0xFF00FF);
	mlx_put_image_to_window(data->mlx->mlx_p, data->mlx->win_p, data->mlx->img.img,0, 0);
	mlx_loop(data->mlx->mlx_p);
	return (EXIT_SUCCESS);
}