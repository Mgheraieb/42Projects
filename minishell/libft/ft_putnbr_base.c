/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:06 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:07 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned int nbr, unsigned int base)
{
	if (base > 16 || base <= 1)
		base = 16;
	if (nbr >= base)
		ft_putnbr_base(nbr / base, base);
	ft_putchar(BASE_HEX[nbr % base]);
}
