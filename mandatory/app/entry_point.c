/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:57:35 by sel-kham          #+#    #+#             */
/*   Updated: 2023/05/05 18:51:51 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	init_img(t_data *data)
{
	int	i;

	i = -1;
	data->mlx->img.img = mlx_new_image(data->mlx->mlx_p, \
		WINDOW_WIDTH, WINDOW_HEIGHT);
	data->mlx->img.addr = mlx_get_data_addr(data->mlx->img.img, \
		&data->mlx->img.bpp, &data->mlx->img.line_len, &data->mlx->img.endian);
	return (1);
}

static int	xpm_init(t_data *data)
{
	int		i;

	i = -1;
	data->textures[0].img.img = mlx_xpm_file_to_image(data->mlx->mlx_p, \
		data->maze->north_side, &data->textures[0].width, \
			&data->textures[0].height);
	data->textures[1].img.img = mlx_xpm_file_to_image(data->mlx->mlx_p, \
		data->maze->west_side, &data->textures[1].width, \
			&data->textures[1].height);
	data->textures[2].img.img = mlx_xpm_file_to_image(data->mlx->mlx_p, \
		data->maze->east_side, &data->textures[2].width, \
			&data->textures[2].height);
	data->textures[3].img.img = mlx_xpm_file_to_image(data->mlx->mlx_p, \
		data->maze->south_side, &data->textures[3].width, \
			&data->textures[3].height);
	while (++i < 4)
	{
		if (!data->textures[i].img.img)
			return (0);
		data->textures[i].img.addr = mlx_get_data_addr(\
			data->textures[i].img.img, &data->textures[i].img.bpp, \
				&data->textures[i].img.line_len, &data->textures[i].img.endian);
	}
	return (1);
}

static void	hooks(t_data *data)
{
	mlx_hook(data->mlx->win_p, ON_KEYDOWN, 0, keydown_handler, (void *) data);
	mlx_hook(data->mlx->win_p, ON_KEYUP, 0, keyup_handler, (void *) data);
	mlx_hook(data->mlx->win_p, ON_DESTROY, 0, destroy_event, (void *) data);
	mlx_loop_hook(data->mlx->mlx_p, default_handler, (void *) data);
	mlx_loop(data->mlx->mlx_p);
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
	maze->map[(int) maze->player_position.y][(int) \
		maze->player_position.x] = '0';
	ft_bzero(data->textures, sizeof(t_texture));
	if (!xpm_init(data))
		fatal_error(TEXTURE_ERROR);
	if (!init_img(data))
		fatal_error(TEXTURE_ERROR);
	events_router(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx->mlx_p, data->mlx->win_p, \
		data->mlx->img.img, 0, 0);
	mlx_destroy_image(data->mlx->mlx_p, data->mlx->img.img);
	hooks(data);
	return (EXIT_SUCCESS);
}
