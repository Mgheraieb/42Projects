/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:31:27 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/07 07:17:29 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR			*open_error(char *filename)
{
	ft_printf("ft_ls: %s: %s\n", filename, strerror(errno));
	ft_strdel(&filename);
	return (0);
}

void		*read_error(char *name)
{
	ft_printf("ft_ls: %s: %s\n", name, strerror(errno));
	ft_strdel(&name);
	return (NULL);
}

uint16_t	error_flag(char c)
{
	ft_printf("ls : illegal option -- %c \n", c);
	ft_printf("usage: ls [-FRacilmrtu] [file ...]\n");
	return (4096);
}
