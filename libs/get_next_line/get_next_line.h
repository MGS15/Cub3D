/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:26:18 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/31 05:25:05 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<stdlib.h>

char	*get_next_line(int fd);
int		ft_strchr2(const char *s, int c);
size_t	ft_strlen2(const char *s);
char	*ft_strjoin2(char *s1, char *s2, int len);
char	*ft_strdup2(const char *s1);

#endif