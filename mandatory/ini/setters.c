/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:50:03 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/12 01:43:19 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_rgb	set_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_coords	set_coords(int x, int y)
{
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

t_player	set_player(t_maze *maze)
{
	t_player	player;

	player.position = maze->player_position;
	player.radius = PLAYER_RADIUS;
	player.turn_direction = 0;
	player.walk_direction = 0;
	player.rotation_angle = M_PI_2;
	player.move_speed = 2.0;
	player.rotation_speed = 2 * (M_PI / 180);
	return (player);
}
