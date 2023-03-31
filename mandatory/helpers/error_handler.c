/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:25:16 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 00:43:09 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	fatal_error(char *err_msg)
{
	printf("%sFatal Error%s%s: %s%s\n", BOLD_RED_COLOR,
		DEFAULT_COLOR, RED_COLOR, err_msg, DEFAULT_COLOR);
	exit(EXIT_FAILURE);
}

void	print_error(char *err_msg)
{
	printf("%sError%s%s: %s%s\n", BOLD_RED_COLOR,
		DEFAULT_COLOR, RED_COLOR, err_msg, DEFAULT_COLOR);
}
