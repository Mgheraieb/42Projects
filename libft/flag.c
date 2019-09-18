/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:05:51 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/27 23:05:51 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	get_format_flag(t_printf *pf)
{
	if ((pf->fi = ft_strichr("# +-0", *pf->format, -1)) > -1)
	{
		pf->ff |= (1 << pf->fi);
		++pf->format;
	}
	(pf->ff & PLUS) ? pf->ff &= ~SPACE : 0;
	(pf->ff & MINUS) ? pf->ff &= ~ZERO : 0;
}

void	get_conv_flag(t_printf *pf)
{
	if (*pf->format == 'l')
		pf->ff |= (pf->format[1] == 'l') ? LONGLONG : LONG;
	else if (*pf->format == 'h')
		pf->ff |= (pf->format[1] == 'h') ? CHAR : SHORT;
	(pf->ff & LONG || pf->ff & SHORT) ? pf->format += 1 : 0;
	(pf->ff & CHAR || pf->ff & LONGLONG) ? pf->format += 2 : 0;
}

void	get_width_precision(t_printf *pf)
{
	int	fwp;

	if (*pf->format > '0' && *pf->format <= '9')
	{
		fwp = ft_atoi(pf->format);
		pf->width = (fwp & ((1 - fwp) >> 31)) | (1 & (~(1 - fwp) >> 31));
		while (*pf->format >= '0' && *pf->format <= '9')
			++pf->format;
	}
	if (*pf->format == '.')
	{
		++pf->format;
		fwp = ft_atoi(pf->format);
		pf->precision = (0 & (fwp >> 31)) | (fwp & (~(fwp >> 31)));
		while (*pf->format >= '0' && *pf->format <= '9')
			++pf->format;
		pf->ff |= ISPRECI;
	}
}

void	ft_conversion(t_printf *pf)
{
	if (pf->arg == 'd' || pf->arg == 'i')
		printf_putnbr(pf);
	else if (*pf->format == 'o')
		printf_putunbr(8, pf);
	else if (*pf->format == 'u')
		printf_putunbr(10, pf);
	else if (*pf->format == 'x' || *pf->format == 'X')
		printf_putunbr(16, pf);
	else if (*pf->format == 's')
		printf_putstr(pf);
	else if (*pf->format == 'p')
		printf_putaddr(pf);
	else if (*pf->format == 'c')
		printf_putchar(pf);
	else
		no_valid_arg(pf);
}

void	get_flag(t_printf *pf)
{
	pf->ff = 0;
	pf->width = 0;
	pf->precision = 1;
	pf->finalsize = 0;
	while (*pf->format != '%' && ft_is_arg(pf) == 0 && ft_is_flag(pf) == 1)
	{
		get_format_flag(pf);
		get_width_precision(pf);
		get_conv_flag(pf);
	}
	pf->arg = *pf->format;
	ft_conversion(pf);
}
