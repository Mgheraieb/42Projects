/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:31:00 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/07 17:06:50 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(double *n, unsigned int i)
{
	uintmax_t	tmp;
	int			arrondi;
	double		nb;

	nb = *n;
	(nb < 0) ? ft_putstr("-") : 0;
	(nb < 0) ? nb = -nb : 0;
	ft_putlongnbr(nb);
	nb -= ((uintmax_t)nb >= UINT_MAX) ? nb : (uintmax_t)nb;
	if (i > 0)
		write(1, ".", 1);
	while (i > 0)
	{
		nb *= 10;
		tmp = (uintmax_t)nb;
		arrondi = (nb - tmp) * 10.0;
		if (arrondi >= 5)
			tmp = (tmp == 9) ? 0 : tmp + 1;
		else if (nb == (double)tmp + 0.99)
			tmp = (tmp == 9) ? 0 : tmp + 1;
		nb -= (double)tmp;
		ft_putlongnbr(tmp);
		i--;
	}
}
