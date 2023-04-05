/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:09:00 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/01 02:41:56 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/**
 * COLORS CONSTANTS
 */
# define BOLD_RED_COLOR "\033[1;31m"
# define RED_COLOR "\033[0;31m"
# define DEFAULT_COLOR "\033[0m"

/**
 * MAP COMPOUNENTS
 */
# define NEWLINE '\n'
# define WHITESPACES " \t\v\f\r\n"

/**
 * FILES EXTENTIONS CONSTANTS
 */
# define XPM_FILE ".xpm"
# define BER_FILE ".ber"

/*
 * MAP ELEMENTS CONSTANTS
 */
# define AREA 48
# define WALL 49
# define SD_E 69
# define SD_N 78
# define SD_S 83
# define SD_W 87
# define EMPTY_SPACE 32

/** 
 * ERRORS MESSAGES CONSTANTS
 */
# define ARGS_ERROR			"Invalid number of arguments\n`Cub3D`\
expects exactly one argument."
# define MEMORY_ERROR		"Memory allocation failed!"
# define MAP_FILE_ERROR		"Invalid file! Check if file exist and\
it's permissions!"
# define MAP_PARSE_ERROR	"Invalid map! Check the map and try again!"
# define ARGUMENTS_ERROR	"Invalid arguments! A map\
in format `*.cub` is required!"
# define RESOLUTION_ERROR	"Invalid resolution! Choose\
a different resolution (1007 x 641 recommended)."

#endif