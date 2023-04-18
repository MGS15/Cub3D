/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:57:35 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/18 23:32:55 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

 void init_img(t_data *data)
{
	data->mlx->img.img = mlx_new_image(data->mlx->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->mlx->img.addr = mlx_get_data_addr(data->mlx->img.img, &data->mlx->img.bpp, \
		 &data->mlx->img.line_len, &data->mlx->img.endian);
}

int	entry_point(t_maze *maze)
{
	t_data	*data;

	data = (t_data *) ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	data->maze = maze;
	data->mlx = graphic_ini();
	data->player = init_player(data->maze);
	mlx_hook(data->mlx->win_p, ON_KEYDOWN, 0, events_router, (void *) data);
	mlx_hook(data->mlx->win_p, ON_DESTROY, 0, destroy_event, (void *) data);
	mlx_loop_hook(data->mlx->mlx_p, default_handler, (void *) data);
	mlx_loop(data->mlx->mlx_p);
	return (EXIT_SUCCESS);
}