/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 06:03:55 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/06 17:00:53 by aechafii         ###   ########.fr       */
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

size_t	get_lognest_line(char **map)
{
	int	i;
	int	len;

	if (!map)
		return (0);
	i = -1;
	len = 0;
	while (map[++i])
		if (len < (int) ft_strlen2(map[i]))
			len = ft_strlen2(map[i]);
	return (len);
}
