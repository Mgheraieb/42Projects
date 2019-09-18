/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:03:59 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/07 03:22:57 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	printf_putnbr(t_printf *pf)
{
	intmax_t	nb;
	int			len;

	len = 0;
	if (pf->ff & SHORT)
		nb = (short)va_arg(pf->ap, int);
	else if (pf->ff & CHAR)
		nb = (char)va_arg(pf->ap, int);
	else if (pf->ff & LONG)
		nb = va_arg(pf->ap, long);
	else if (pf->ff & LONGLONG)
		nb = va_arg(pf->ap, long long);
	else
		nb = va_arg(pf->ap, int);
	(pf->ff & ZERO) ? pf->precision = pf->width : 0;
	ft_printf_itoa(nb, len, pf);
}

void	printf_putunbr(int base, t_printf *pf)
{
	uintmax_t	nb;

	if (pf->ff & SHORT)
		nb = (unsigned short)va_arg(pf->ap, unsigned int);
	else if (pf->ff & CHAR)
		nb = (unsigned char)va_arg(pf->ap, unsigned int);
	else if (pf->ff & LONG)
		nb = va_arg(pf->ap, unsigned long);
	else if (pf->ff & LONGLONG)
		nb = va_arg(pf->ap, unsigned long long);
	else
		nb = va_arg(pf->ap, unsigned int);
	ft_printf_itoa_base(nb, nb, pf, base);
}

void	printf_putstr(t_printf *pf)
{
	char	*str;
	int		size;

	if (!(str = va_arg(pf->ap, char*)))
		create_buffer("(null)", 6, pf);
	else
	{
		size = ft_strlen(str);
		(pf->ff & ISPRECI) ? size = (pf->precision & (pf->precision - size)
				>> 31) | (size & (~(pf->precision - size) >> 31)) : 0;
		pf->width = (pf->width - size) > 0 ? (pf->width - size) : 0;
		put_width(pf, 0);
		create_buffer(str, size, pf);
		put_width(pf, 1);
	}
}

void	printf_putaddr(t_printf *pf)
{
	void *str;

	str = va_arg(pf->ap, void*);
	pf->ff &= ~DIEZ;
	pf->width = (pf->finalsize > pf->width) ? 0
		: pf->width - pf->finalsize;
	pf->ff |= DIEZ;
	pf->ff |= ISADDRESS;
	ft_printf_itoa_base((uintmax_t)str, (uintmax_t)str, pf, 16);
}

void	printf_putchar(t_printf *pf)
{
	char tmp[2];

	tmp[0] = va_arg(pf->ap, int);
	pf->width = pf->width - (pf->finalsize + 1);
	(pf->width < 0) ? pf->width = 0 : 0;
	put_width(pf, 0);
	create_buffer(tmp, 1, pf);
	put_width(pf, 1);
}
