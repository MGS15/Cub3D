/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:14:05 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 21:35:02 by sel-kham         ###   ########.fr       */
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

/* ______________________ HELPER FUNCTIONS ______________________ */
/**
 * @brief Prints error with red color and exits the proccess.
 * @param err_msg error message to print.
 * @return void 
 */
void		fatal_error(char *err_msg);
/**
 * @brief Prints error with red color without exiting the proccess.
 * @param err_msg error message to print.
 * @return void 
 */
void		print_error(char *err_msg);
/**
 * @brief Iterates through a double pointer and frees memory allocated
 * * dynamically.
 * @param pointer The double pointer to be freed.
 * @return void
 */
void		free_double_pointer(void **pointer);
/**
 * @brief Frees all the elements of t_maze struct.
 * @param maze Pointer to t_maze to be freed.
 * @return void
 */
void		free_maze(t_maze *maze);
/**
 * @brief Checks if the file provided has the specified file extension.
 * @param dir Absolute/Relative path to the file to be checked.
 * @param ext Expected extension o the file.
 * @return true if the extension is valid.
 * @return false if otherwise.
 */
bool		extention_checker(char *dir, const char *ext);
/**
 * @brief Calculates the size of a double pointer.
 * @param pointer The double pointer to calculate the its size
 * @return size_t value representing the size of the double pointer.
 */
size_t		double_pointer_len(void **pointer);
/**
 * @brief Checks if a string passed as argument is numeric or not.
 * 
 * @param s the string to check
 * @return true if the string is numeric
 * @return false otherwise.
 */
bool		ft_isnumeric(const char *s);

/* ______________________ INI FUNCTIONS ______________________ */
/**
 * @brief Allocates a pointer to t_rgb type object and initialize its elements
 * * with -1 value.
 * @return t_rgb* in the case of successful allocation.
 * @return NULL if allocation failed.
 */
t_rgb		*init_rgb(void);
/**
 * @brief Allocates a pointer to t_coords type object
 * * and initialize its elements with -1 value.
 * @return t_coords* in the case of successful allocation.
 * @return NULL if allocation failed.
 */
t_coords	*init_coords(void);
/**
 * @brief Allocates a pointer to t_maze type object
 * * and initialize its elements to NULL.
 * @return t_maze* in the case of successful allocation.
 * @return NULL if allocation failed.
 */
t_maze		*init_maze(void);
/**
 * @brief Set the rgb object values
 * 
 * @param r red value
 * @param g green value
 * @param b blue value
 * @return t_rgb value
 */
t_rgb		set_rgb(int r, int g, int b);

/* ______________________ INI FUNCTIONS ______________________ */
/**
 * @brief Parses the specified map file fills the t_maze structure
 * * with required information.
 * @param file_dir the full path to the map file.
 * @return t_maze* in the case of successful parsing.
 * @return NULL if parsing or allocation failed.
 */
t_maze		*get_maze(int fd);
/**
 * @brief This function gets the texture config from map
 * * file and stores in t_maze structure.
 * @param maze the double pointer to t_maze structure where to store
 * * the texture config.
 * @param line One line from the map file.
 * @return 1 in a successfull parsing.
 * @return -1 in case of allocation failure.
 * @return 0 Interger in case of parsing failure.
 */
int			config_parser(t_maze **maze, char *line);

#endif