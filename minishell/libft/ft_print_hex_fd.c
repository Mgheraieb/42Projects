/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:57 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:00 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_print_hex_fd(unsigned int value, int length, int fd)
{
	char	*base;
	char	output[sizeof(int) * 2];
	int		i;

	i = 7;
	base = "0123456789abcdef";
	while (value > 0)
	{
		output[i] = base[value % 16];
		value /= 16;
		i--;
	}
	while (i >= 8 - length && i >= 0)
		output[i--] = '0';
	while (i < 8)
		ft_putchar_fd(output[i++], fd);
}
