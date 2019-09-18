/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 14:09:22 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/11 11:20:57 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_isntflag(char *flag, int check, int *len)
{
	(check != -1 && check != 0) ? *len += check : 0;
	(check != 0) ? ft_strdel(&flag) : 0;
	return (*len);
}

int		ft_isaflag(char *flag, int *len, void *ap)
{
	*len += (flag[ft_strlen(flag) - 1] != 'f')
		? ft_read_flag(ap, flag) : 0;
	return (*len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		check;
	char	*flag;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			check = ft_get_flag(++format, &flag);
			format += ft_strlen(flag);
			(check == 0 && flag[ft_strlen(flag) - 1] == 'f') ?
				len += ft_readfloat(va_arg(ap, double), flag) : 0;
			(check == 0) ? ft_isaflag(flag, &len, va_arg(ap, void*)) : 0;
			(check != 0) ? ft_isntflag(flag, check, &len) : 0;
		}
		if (*format && *format != '%')
		{
			write(1, format++, 1);
			len++;
		}
	}
	return (len);
}
