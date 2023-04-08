/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:54:31 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/08 00:31:46 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	graphic_ini(t_mlx *mlx)
{
	mlx->mlx_p = mlx_init();
	if (!mlx->mlx_p)
		return (0);
	mlx->win_p = mlx_new_window(mlx->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!mlx->win_p)
		return (0);
	mlx->img.img = mlx_new_image(mlx->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->img.img)
		return (0);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
		 &mlx->img.line_len, &mlx->img.endian);
	return (1);
}
