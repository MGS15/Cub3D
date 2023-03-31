/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:13:43 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 01:20:23 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3D.h"

int	main(int c, char **v)
{
	t_maze	*maze;

	if (c != 2)
		fatal_error(ARGS_ERROR);
	if (v[1] && v[1][0])
		if (!extention_checker(v[1], ".cub"))
			fatal_error(ARGUMENTS_ERROR);
	maze = get_maze(v[1]);
	if (!maze)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
