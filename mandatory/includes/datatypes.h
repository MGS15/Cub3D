/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:08:41 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/09 01:47:32 by sel-kham         ###   ########.fr       */
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
	char		*north_side;
	char		*west_side;
	char		*east_side;
	char		*south_side;
	t_rgb		*floor;
	t_rgb		*ceilling;
	char		**map;
	size_t		map_width;
	size_t		map_high;
	t_coords	player_position;
}	t_maze;

typedef struct img_s
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct mlx_s
{
	void	*mlx_p;
	void	*win_p;
	t_img	img;
}	t_mlx;

typedef struct player_s
{
	t_coords	position;
	int			radius;
	short		turn_direction;
	short		walk_direction;
	double		rotation_angle;
	double		move_speed;
	double		rotation_speed;
}	t_player;

#endif