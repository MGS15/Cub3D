/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:14:05 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 00:44:48 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include<stdio.h>
# include<math.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdbool.h>
# include "datatypes.h"
# include "macros.h"
# include "../../libs/libft/libft.h"
# include "../../libs/get_next_line/get_next_line.h"

/*
 * HELPERS FUNCTIONS
 */
void		fatal_error(char *err_msg);
void		print_error(char *err_msg);
int			file_handler(char *file_dir);

/*
 * INI FUNCTIONS
 */
t_rgb		*init_rgb(void);
t_coords	*init_coords(void);
t_maze		*init_maze(void);

#endif