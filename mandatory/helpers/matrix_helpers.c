/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 06:03:55 by sel-kham          #+#    #+#             */
/*   Updated: 2023/04/01 06:06:17 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

size_t	martix_len(char **matrix)
{
	size_t	len;

	len = -1;
	if (!matrix)
		return (0);
	while (matrix[++len])
		;
	return (len);
}
