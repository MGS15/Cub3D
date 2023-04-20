/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:08:41 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/20 05:50:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

typedef struct coord_s
{
	double	x;
	double	y;
}	t_coords;

typedef struct rgb_s
{
	short	r;
	short	g;
	short	b;
}	t_rgb;

typedef struct vector_s
{
	double	x;
	double	y;
}	t_vector;

typedef struct event_s
{
	int	vertical_movement;
	int	horizontal_movement;
	int	rotation;
	int keycode;
}	t_event;

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

typedef struct ray_s
{
	t_vector ray_v;
	t_vector change;
	t_vector	change_in_sqr;
	int	map_x;
	int	map_y;
	int			inc_x;
	int			inc_y;
	char	interction;
	int	wall_height;
	int draw_start;
	int draw_end;
	double	intersection_x;
}	t_ray;

typedef struct player_s
{
	t_coords	position;
	int			radius;
	double		rotation_speed;
	double		walk_speed;
	t_vector	direction;
	t_vector	plane;
}	t_player;

typedef struct data_s
{
	t_player	*player;
	t_mlx		*mlx;
	t_maze		*maze;
	t_event		event;
}	t_data;

#endif