/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:39:04 by mgheraie          #+#    #+#             */
/*   Updated: 2019/01/21 17:46:27 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_is_placable(char *tetris, char *map, int imap)
{
	int i;
	int check;
	int dist;

	dist = ft_sqrt(ft_strlen(map)) - 4;
	i = 0;
	while (tetris[i] == '.')
		i++;
	check = 0;
	while (tetris[i])
	{
		if (check != 0 && tetris[i] != '#')
			imap += dist;
		if (tetris[i] == '#')
		{
			if (map[imap] != '.' && check != 0)
				return (-1);
			check++;
		}
		i++;
	}
	return (1);
}

int		ft_tetri_ok(char *map, int nbt)
{
	int check;
	int i;

	check = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == nbt + 'A')
			check++;
		if (check == 4)
			return (1);
		i++;
	}
	return (-1);
}

int		ft_put_in_tab(char *tetri, char *map, int imap, int nbt)
{
	int i;
	int check;
	int len;

	len = ft_sqrt(ft_strlen(map));
	i = 0;
	check = 0;
	while (tetri[i] != '\0')
	{
		if (check == 1 && tetri[i] != '#')
		{
			imap += len - 4;
			check = 0;
		}
		if (tetri[i++] == '#')
		{
			if (map[imap] != '.' || (check == 1 && imap % len == 0))
				return (-1);
			check = 1;
			map[imap] = nbt + 'A';
		}
		imap++;
	}
	return (ft_tetri_ok(map, nbt));
}

void	ft_remove_tetri(char *map, int nbt)
{
	char	c;
	int		i;

	c = nbt + 'A';
	i = 0;
	while (map[i])
	{
		if (map[i] == c)
			map[i] = '.';
		i++;
	}
}

int		ft_fillit(char **tetris, char *map, int imap, int nbt)
{
	int		check;
	char	*tmp;

	if (tetris[nbt] == NULL)
		return (1);
	tmp = &tetris[nbt][ft_strchri(tetris[nbt], '#')];
	if (ft_strstr(tmp, "##..##") != NULL && ft_lentab(tetris) == 1)
	{
		ft_memset(map, 'A', 4);
		return (1);
	}
	while (map[imap])
	{
		if (ft_put_in_tab(tmp, map, imap, nbt) > 0)
		{
			if ((check = ft_fillit(tetris, map, 0, nbt + 1)) > 0)
				return (1);
			else
				ft_remove_tetri(map, nbt);
		}
		else
			ft_remove_tetri(map, nbt);
		imap++;
	}
	return (-1);
}
