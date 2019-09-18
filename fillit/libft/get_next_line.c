/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:12:28 by mgheraie          #+#    #+#             */
/*   Updated: 2018/12/03 14:28:46 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read_line(const int fd, char **nl)
{
	int		r;
	char	*buff;

	r = 1;
	buff = NULL;
	while (r > 0 && (!(ft_strchr(*nl, '\n'))))
	{
		buff = ft_strnew(BUFF_SIZE);
		if ((r = read(fd, buff, BUFF_SIZE)) < 0)
		{
			free(buff);
			return (-1);
		}
		if (!(*nl = ft_strjoin_free(nl, &buff)))
			return (-1);
	}
	return (r);
}

int		ft_get_ret(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int		ft_error(int fd, char **line, char **nl)
{
	int r;

	r = 0;
	if (fd < 0 || fd > 10240 || line == NULL)
		return (-1);
	if (!(nl[fd]))
		nl[fd] = ft_strdup("");
	if ((r = ft_read_line(fd, &nl[fd])) < 0)
		return (-1);
	return (r);
}

int		get_next_line(const int fd, char **line)
{
	static char		*nl[10240];
	char			*tmp;
	int				r;
	int				ret;

	tmp = NULL;
	if ((r = ft_error(fd, line, nl)) == -1)
		return (-1);
	if (r == 0 && ft_memcmp(nl[fd], "", 1) == 0)
	{
		free(nl[fd]);
		nl[fd] = NULL;
		return (0);
	}
	ret = ft_get_ret(nl[fd]);
	if (!(*line = ft_strsub(nl[fd], 0, ret)))
		return (-1);
	if (!(tmp = ft_strsub(nl[fd], ret + 1, ft_strlen(nl[fd]) - ret - 1)))
		return (-1);
	free(nl[fd]);
	nl[fd] = tmp;
	return (1);
}
