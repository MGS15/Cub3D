/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:03:51 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 00:46:39 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_maze	*get_maze(char *file_dir)
{
	t_maze	*maze;
	int		fd;

	fd = open(file_dir, O_RDONLY);
	if (fd < 0)
		return (print_error(MAP_FILE_ERROR), NULL);
	maze = init_maze();
	if (!maze)
		return (print_error(MEMORY_ERROR), NULL);
}
