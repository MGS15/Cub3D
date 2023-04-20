/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:50:03 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/19 02:40:23 by sel-kham         ###   ########.fr       */
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

t_vector	set_vector(double x, double y)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	return (v);
}
