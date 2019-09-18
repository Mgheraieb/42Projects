/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:31:29 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/06 11:33:38 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (*str)
		ft_putchar(*str);
	if (*str++)
		ft_putstr(str++);
}

int		ft_display_file(char *src)
{
	int		size;
	char	c;

	size = open(src, O_RDONLY);
	if (size < 0)
		return (1);
	while (read(size, &c, 1))
		write(1, &c, 1);
	close(size);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	ft_display_file(av[1]);
	return (0);
}
