/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:10:16 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/30 05:22:17 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_rgb	*init_rgb(void)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	rgb->r = -1;
	rgb->g = -1;
	rgb->b = -1;
	return (rgb);
}

t_coords	*init_coords(void)
{
	t_coords	*coords;

	coords = malloc(sizeof(t_coords));
	if (!coords)
		return (NULL);
	coords->x = -1;
	coords->y = -1;
	return (coords);
}

t_maze	*init_maze(void)
{
	t_maze	*maze;

	maze = ft_calloc(1, sizeof(t_maze));
	return (maze);
}
