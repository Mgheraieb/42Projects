/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:34:36 by mgheraie          #+#    #+#             */
/*   Updated: 2018/12/29 14:15:09 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned int nb, unsigned int base)
{
	char *s;

	s = ft_strdup("ABCDEF");
	if (nb > base - 1)
	{
		ft_putnbr_base(nb / base, base);
		ft_putnbr_base(nb % base, base);
	}
	else
	{
		if (nb < 10)
			ft_putnbr(nb);
		else
			ft_putchar(s[nb - 10]);
	}
	ft_strdel(&s);
}
