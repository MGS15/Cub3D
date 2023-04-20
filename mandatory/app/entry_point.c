/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:57:35 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/20 05:40:47 by sel-kham         ###   ########.fr       */
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
	ft_bzero(&data->event, sizeof(t_event));
	maze->map[(int) maze->player_position.y][(int) maze->player_position.x] = '0';
	mlx_hook(data->mlx->win_p, ON_KEYDOWN, 0, keydown_handler, (void *) data);
	mlx_hook(data->mlx->win_p, ON_KEYUP, 0, keyup_handler, (void *) data);
	mlx_hook(data->mlx->win_p, ON_DESTROY, 0, destroy_event, (void *) data);
	mlx_loop_hook(data->mlx->mlx_p, default_handler, (void *) data);
	mlx_loop(data->mlx->mlx_p);
	return (EXIT_SUCCESS);
}