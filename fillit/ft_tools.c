/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:29:49 by mgheraie          #+#    #+#             */
/*   Updated: 2018/12/14 15:41:36 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_get_dot(char *map, int start)
{
	while (map[start] && map[start] != '.')
		start++;
	return (start);
}

char	*ft_create_map(int i, char *res)
{
	i = i * i;
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_memset(res, '.', i);
	return (res);
}

int		ft_sqrt(int nb)
{
	int i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i < nb / i && i * i != nb)
		i++;
	if (i * i == nb)
		return (i);
	return (i);
}

void	ft_putit(char *s)
{
	int i;
	int sizemap;
	int put;

	sizemap = ft_sqrt(ft_strlen(s));
	put = 4 + (sizemap - 4);
	i = 0;
	while (s[i])
	{
		if (i > 0 && i % put == 0)
			ft_putendl("");
		ft_putchar(s[i]);
		i++;
	}
	ft_putendl("");
}

int		ft_lentab(char **tetris)
{
	int i;

	i = 0;
	while (tetris[i])
		i++;
	return (i);
}
