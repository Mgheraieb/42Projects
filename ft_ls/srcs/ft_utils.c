/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:18:10 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/12 19:27:23 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_isflagls(char c)
{
	if (c != 'l' && c != 'R' && c != 'a' && c != 'r' && c != 't' && c != 'F'
			&& c != 'c' && c != 'i' && c != 'u' && c != '1' && c != 'm'
			&& c != 'G')
		return (-1);
	return (1);
}

void		ft_checkflag(char c, uint16_t *flag)
{
	if (c == 'l' && !(*flag & FLAGL) && ((*flag & FLAGM) ? *flag -= FLAGM : 1))
		*flag = *flag | FLAGL;
	else if (c == 'R' && !(*flag & FLAGR))
		*flag = *flag | FLAGR;
	else if (c == 'a' && !(*flag & FLAGA))
		*flag = *flag | FLAGA;
	else if (c == 'r' && !(*flag & FLAGREV))
		*flag = *flag | FLAGREV;
	else if (c == 't' && !(*flag & FLAGT))
		*flag = *flag | FLAGT;
	else if (c == 'F' && !(*flag & FLAGF))
		*flag = *flag | FLAGF;
	else if (c == 'c' && !(*flag & FLAGC))
		*flag = *flag | FLAGC;
	else if (c == 'i' && !(*flag & FLAGI))
		*flag = *flag | FLAGI;
	else if (c == 'u' && !(*flag & FLAGU))
		*flag = *flag | FLAGU;
	else if (c == '1' && !(*flag & FLAG1))
		*flag = *flag | FLAG1;
	else if (c == 'm' && !(*flag & FLAGM) && (*flag = *flag | FLAGM))
		(*flag & FLAGL) ? *flag -= FLAGL : 0;
}

uint16_t	getflag(char **av)
{
	uint16_t	flag;
	size_t		i;
	size_t		j;

	i = -1;
	flag = 0;
	while (av[++i])
	{
		if (ft_strlen(av[i]) == 1 && !ft_strcmp(av[i], "-"))
			return (2048);
		j = -1;
		while (av[i][++j])
		{
			if (av[i][0] != '-')
				return (flag);
			(av[i][j] == '-' && j == 0) ? j++ : 0;
			if (ft_isflagls(av[i][j]) == 1)
				ft_checkflag(av[i][j], &flag);
			else
				return (error_flag(av[i][j]));
		}
	}
	return (flag);
}

uint8_t		ft_setmode(mode_t i)
{
	uint8_t mode;

	mode = 0;
	if (i & RU)
		mode = mode | RU;
	if (i & WU)
		mode = mode | WU;
	if (i & XU)
		mode = mode | XU;
	if (i & RG)
		mode = mode | RG;
	if (i & WG)
		mode = mode | WG;
	if (i & XG)
		mode = mode | XG;
	if (i & RO)
		mode = mode | RO;
	if (i & WO)
		mode = mode | WO;
	if (i & XO)
		mode = mode | XO;
	return (mode);
}

time_t		settime(struct stat buf, uint16_t flag)
{
	if (flag & FLAGC)
		return (buf.st_ctime);
	else if (flag & FLAGU)
		return (buf.st_atime);
	return (buf.st_mtime);
}
