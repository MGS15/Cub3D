/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:10:51 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/18 20:10:56 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

double	deg_to_rad(double rad)
{
	return (rad * (180 / M_PI));
}

double	rad_to_deg(double deg)
{
	return (deg * (M_PI / 180));
}
