/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:58:14 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/11 11:18:44 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_readfloat(double ap, char *flag)
{
	int i;

	i = ft_getprecision(flag);
	(i == 0) ? i = 6 : 0;
	ft_putfloat(&ap, (unsigned int)i);
	ft_strdel(&flag);
	return (ft_intlen((int)ap) + i + 1);
}

char	*ft_noarg(char *flag, char ap)
{
	char *res;

	res = ft_flagsize(flag, 'c', "A", 0);
	if (res == NULL)
	{
		ft_putspecchar((char)ap);
		return (ft_strdup(""));
	}
	else if (ft_strchr(flag, '-') != NULL)
	{
		ft_putspecchar((char)ap);
		ft_putstr(res);
	}
	else
	{
		ft_putstr(res);
		ft_putspecchar((char)ap);
	}
	return (res);
}

int		ft_isflag(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == ' ' || c == 'l' || c == 'h'
			|| c == '.' || ft_isdigit(c) == 1)
		return (1);
	return (-1);
}

int		ft_isconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' ||
			c == 'u' || c == 'x' || c == 'X' || c == 'f' ||
			c == 'S' || c == 'C' || c == 'F')
		return (1);
	return (-1);
}

int		ft_skip(char *flag, char arg, char *ap)
{
	if (arg == 'c')
		return (1);
	if (arg == 'p')
		return (2);
	if (ft_strchr(ap, '-') == NULL && (arg == 'd' || arg == 'i'))
		if (ft_strchr(flag, ' ') != NULL || (ft_strchr(flag, '+') != NULL))
			return (1);
	if (ft_strchr(flag, '#') != NULL)
	{
		if (arg == 'o')
			return (1);
		if (arg == 'x' || arg == 'X')
			return (2);
	}
	return (0);
}
