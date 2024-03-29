/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:00 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:01 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_hex_char(unsigned char c)
{
	const char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

static void	print_hex_line(unsigned char *curr, unsigned char *end)
{
	unsigned int i;

	i = 0;
	ft_print_hex((unsigned int)curr, 8);
	ft_putchar(':');
	ft_putchar(' ');
	while (i < 16)
	{
		if (curr + i < end)
			print_hex_char(curr[i]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void		*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*curr;
	unsigned char	*end;
	unsigned int	i;

	curr = (unsigned char*)addr;
	end = curr + size;
	while (curr < end)
	{
		print_hex_line(curr, end);
		i = 0;
		while (i < 16 && curr + i < end)
		{
			if (!ft_isprint(curr[i]))
				ft_putchar('.');
			else
				ft_putchar(curr[i]);
			i++;
		}
		ft_putchar('\n');
		curr += 16;
	}
	return (addr);
}
