/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <mgheraie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:06:25 by mgheraie          #+#    #+#             */
/*   Updated: 2019/01/22 16:30:20 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_count_tetris(char *tetris)
{
	int check;

	check = 0;
	while (*tetris)
	{
		if (*tetris == '#')
			check++;
		if (*tetris != '.' && *tetris != '#')
			return (-1);
		tetris++;
	}
	if (check != 4)
		return (-1);
	return (1);
}

int		ft_verif_tetris(char **tetris)
{
	int i;
	int j;
	int check;

	i = 0;
	while (tetris[i])
	{
		check = 0;
		j = 0;
		while (tetris[i][j])
		{
			if (tetris[i][j] == '#')
			{
				(j != 0 && tetris[i][j - 1] == '#') ? check++ : 0;
				(tetris[i][j + 1] == '#') ? check++ : 0;
				(j > 3 && tetris[i][j - 4] == '#') ? check++ : 0;
				(j < 14 && tetris[i][j + 4] == '#') ? check++ : 0;
			}
			j++;
		}
		if (check > 8 || check < 6 || ft_count_tetris(tetris[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

char	*ft_get_tetri(const int fd)
{
	char	*line;
	char	*tetris;
	char	*tmp;
	int		r;
	int		nb_l;

	tmp = ft_strnew(0);
	nb_l = 0;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		nb_l++;
		if ((nb_l % 5 != 0 && ft_strlen(line) != 4) ||
				(nb_l % 5 == 0 && ft_strcmp(line, "") != 0))
			return (NULL);
		if ((nb_l % 5 == 0 && ft_strcmp(line, "") == 0))
			ft_strcat(line, " ");
		if (!(tmp = ft_strjoin_free(&tmp, &line)))
			return (NULL);
	}
	tetris = tmp;
	ft_strdel(&tmp);
	r = ft_countword(tetris, ' ');
	if ((r * 4 + r - 1) != nb_l || r < 0 || ft_countword(tetris, ' ') >= 26)
		return (NULL);
	return (tetris);
}

char	**ft_parsing(char **av)
{
	int		fd;
	char	**tetris;
	char	*map;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (NULL);
	if (!(map = ft_get_tetri(fd)))
		return (NULL);
	if (!(tetris = ft_strsplit(map, ' ')))
	{
		free(map);
		return (NULL);
	}
	if (ft_verif_tetris(tetris) == -1)
	{
		ft_tabdel(tetris, NULL);
		return (NULL);
	}
	return (tetris);
}

void	ft_tabdel(char **s, char *map)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_strdel(&s[i]);
		i++;
	}
	free(s);
	if (map != NULL)
	{
		ft_putit(map);
		free(map);
	}
}
