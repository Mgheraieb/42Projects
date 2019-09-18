/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:47 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:36:48 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c, int amount)
{
	int n;

	n = amount;
	while (n-- > 0)
		ft_putchar(c);
	return (ft_floor(0, amount));
}
