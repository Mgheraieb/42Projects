/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:24:08 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/13 18:14:53 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_getbase(char arg)
{
	if (arg == 'o')
		return (8);
	else if (arg == 'x' || arg == 'X' || arg == 'p')
		return (16);
	return (10);
}

int		ft_getlen(char *flag)
{
	int i;

	i = 0;
	while (*flag)
	{
		if (*flag == 'l')
			return (1);
		if (*flag == 'h')
			i++;
		flag++;
	}
	i = (i > 0) ? -i : i;
	return (i);
}

int		ft_get_flag(const char *format, char **flag)
{
	int i;

	*flag = NULL;
	i = 0;
	if (*format == '\0')
		return (-1);
	while (format[i])
	{
		if (ft_isconv(format[i]) == 1)
			break ;
		if ((ft_isconv(format[i]) == -1 && ft_isflag(format[i]) == -1) ||
				format[i] == '%')
			break ;
		i++;
	}
	*flag = ft_strsub(format, 0, i + 1);
	return (ft_parsingflag(*flag));
}

int		ft_read_flag(void *ap, char *flag)
{
	char	*tmp;
	int		i;
	char	arg;

	i = -1;
	arg = flag[ft_strlen(flag) - 1];
	if (!(tmp = ft_redirconv(flag, ap)))
	{
		ft_strdel(&flag);
		return (-1);
	}
	i = ft_strlen(tmp);
	(arg == 'c') ? i++ : 0;
	(arg != 'c' && arg != 'C' && arg != 'f') ? ft_putstr(tmp) : 0;
	ft_strdel(&flag);
	ft_strdel(&tmp);
	return (i);
}

char	*ft_redirconv(char *flag, void *ap)
{
	char	arg;
	char	*conv;

	arg = flag[ft_strlen(flag) - 1];
	arg = (arg != 'X') ? ft_tolower(arg) : arg;
	conv = NULL;
	flag[ft_strlen(flag) - 1] = arg;
	if (arg == 's')
		conv = ft_readstr(ap);
	else if (arg == 'd' || arg == 'i')
		conv = ft_readint(flag, ap);
	else if (arg == 'o' || arg == 'u' || arg == 'x' || arg == 'X' || arg == 'p')
		conv = ft_readuint(flag, ap, arg);
	else if (arg == 'c')
		conv = ft_readchar(flag, ap);
	else if (arg == 'f')
		return (NULL);
	conv = (conv != NULL) ? ft_redirflag(flag, arg, conv) : 0;
	return (conv);
}
