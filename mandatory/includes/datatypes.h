/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:08:41 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/30 04:08:51 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

typedef struct coord_s
{
	int	x;
	int	y;
}	t_coords;

typedef struct rgb_s
{
	short	r;
	short	g;
	short	b;
}	t_rgb;

typedef struct maze_s
{
	char	*north_side;
	char	*west_side;
	char	*east_side;
	char	*south_side;
	t_rgb	*floor;
	t_rgb	*ceilling;
	char	**map;
}	t_maze;

#endif