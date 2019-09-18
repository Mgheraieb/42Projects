/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:50:15 by mgheraie          #+#    #+#             */
/*   Updated: 2018/12/07 13:17:11 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include "libft.h"

int ft_error(int fd, char **line, char **nl);
int ft_read_line(const int fd, char **nl);
int ft_get_ret(char *s);
int get_next_line(const int fd, char **line);
#endif
