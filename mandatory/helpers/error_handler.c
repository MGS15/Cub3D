/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:25:16 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/07 23:03:16 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	fatal_error(char *err_msg)
{
	printf("%sFatal Error%s%s: %s%s\n", BOLD_RED_COLOR,
		DEFAULT_COLOR, RED_COLOR, err_msg, DEFAULT_COLOR);
	exit(EXIT_FAILURE);
}

void	print_error(char *err_msg)
{
	printf("%sError%s%s: %s%s\n", BOLD_RED_COLOR,
		DEFAULT_COLOR, RED_COLOR, err_msg, DEFAULT_COLOR);
}

void	free_double_pointer(void **pointer)
{
	int	i;

	if (!pointer)
		return ;
	i = -1;
	while (pointer[++i])
		free(pointer[i]);
	free(pointer);
	pointer = NULL;
}

void	free_maze(t_maze *maze)
{
	if (!maze)
		return ;
	if (maze->north_side)
		free(maze->north_side);
	if (maze->south_side)
		free(maze->south_side);
	if (maze->west_side)
		free(maze->west_side);
	if (maze->east_side)
		free(maze->east_side);
	if (maze->floor)
		free(maze->floor);
	if (maze->ceilling)
		free(maze->ceilling);
	free(maze);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->win_p)
			mlx_destroy_window(mlx->mlx_p, mlx->win_p);
		if (mlx->img.img)
			mlx_destroy_image(mlx->mlx_p, mlx->img.img);
		if (mlx->mlx_p)
			free(mlx->mlx_p);
		free(mlx);
	}
	mlx = NULL;
}
