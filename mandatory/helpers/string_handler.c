/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:28:16 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 00:45:31 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	ft_isspace(int c)
{
	int	res;

	res = 0;
	if (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		res = 1;
	return (res);
}

bool	extention_checker(char *dir, const char *ext)
{
	char	*tmp_ext;

	tmp_ext = dir + ft_strlen(dir) - 4;
	if (!ft_strncmp(tmp_ext, ext, ft_strlen(tmp_ext)))
		return (true);
	return (false);
}
