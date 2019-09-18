/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 14:15:34 by mgheraie          #+#    #+#             */
/*   Updated: 2018/12/29 14:16:29 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlongnbr(long int nb)
{
	if (nb == LONG_MIN)
	{
		ft_putchar('-');
		ft_putchar('9');
		ft_putlongnbr(223372036854775808);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putlongnbr(nb * -1);
	}
	else if (nb > 9)
	{
		ft_putlongnbr(nb / 10);
		ft_putlongnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
