/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:07:33 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/13 02:11:20 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	destroy_game(void *data)
{
	free_maze(((t_data *) data)->maze);
	free_mlx(((t_data *) data)->mlx);
	free(((t_data *) data)->player);
	exit(EXIT_SUCCESS);
}

int	events_router(int e, void *data)
{
	if (e == ESC_KEY)
		destroy_game(data);
	else
		printf("%d\n", e);
	return (EXIT_SUCCESS);
}

