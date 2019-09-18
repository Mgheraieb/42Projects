/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:48 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:36:49 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char_fd(char c, int amount, int fd)
{
	int n;

	n = amount;
	while (n-- > 0)
		ft_putchar_fd(c, fd);
	return (ft_floor(0, amount));
}
