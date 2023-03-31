/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:28:16 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 19:58:21 by sel-kham         ###   ########.fr       */
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

size_t	double_pointer_len(void **pointer)
{
	int	i;

	if (!pointer)
		return (0);
	i = -1;
	while (pointer[++i])
		;
	return (i);
}

bool	ft_isnumeric(const char *s)
{
	if (!s)
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}
