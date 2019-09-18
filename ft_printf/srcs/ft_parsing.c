/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:39:36 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/11 10:59:43 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_error_arg(char *flag, char arg)
{
	char	*tmp;
	int		i;

	if (ft_isflag(arg) == 1)
		return (-1);
	tmp = ft_noarg(flag, arg);
	i = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (i + 1);
}

int		ft_parsingflag(char *flag)
{
	int i;

	i = 0;
	while (flag[i] && ft_isconv(flag[i]) == -1)
	{
		if (ft_isflag(flag[i]) == -1)
			return (ft_error_arg(flag, flag[i]));
		i++;
	}
	if (flag[i] == '\0' && (ft_isconv(flag[i - 1] == 1) ||
				ft_isflag(flag[i - 1] == -1)))
		return (ft_error_arg(flag, flag[i - 1]));
	return (0);
}

int		ft_getprecision(char *flag)
{
	int precision;

	precision = 0;
	while (*flag && *flag != '.')
		flag++;
	if (*flag == '\0')
		return (0);
	flag++;
	precision = ft_atoi(flag);
	return (precision);
}

char	*ft_redirflag(char *flag, char arg, char *ap)
{
	char	*tmp;
	int		precision;

	precision = (arg == 'c') ? 0 : ft_getprecision(flag);
	tmp = NULL;
	if (ft_strchr(flag, '.') != NULL && arg != 'c')
		ap = ft_precision(arg, ap, precision);
	(arg != 'c') ? tmp = ft_flagsize(flag, arg, ap, precision) : 0;
	if (arg == 'p' || (ft_strchr(flag, '#') != NULL && tmp && tmp[0] != '0'))
	{
		ap = ft_flagtag(arg, ap);
		(arg != 'p') ? flag[ft_strchri(flag, '#')] = '.' : 0;
	}
	if (ft_strchr(flag, '+') != NULL)
		ap = ft_flagplus(arg, ap);
	if (tmp != NULL)
		ap = ft_structflag(flag, ap, tmp);
	if (ft_strchr(flag, ' ') != NULL && ft_strchr(flag, '+') == NULL)
		ap = ft_flagspace(arg, ap);
	else if (ft_strchr(flag, '#') != NULL)
		ap = ft_flagtag(arg, ap);
	ft_clean(ap);
	return (ap);
}

char	*ft_flagtag(char arg, char *ap)
{
	char *tmp;

	if (ft_strcmp(ap, "0") == 0 && arg != 'o' && arg != 'X' && arg != 'x' &&
			arg != 'p')
		return (ap);
	tmp = NULL;
	if (((arg == 'x' || arg == 'X') && ft_strcmp(ap, "0") == 0))
		return (ap);
	if (arg == 'p')
		tmp = ft_strdup("0x");
	else if (arg == 'x' && *ap)
		tmp = ft_strdup("0x");
	else if (arg == 'X' && *ap)
		tmp = ft_strdup("0X");
	else if (arg == 'o')
	{
		if (ap[0] != '0')
			tmp = ft_strdup("0");
		else
			tmp = ft_strnew(0);
	}
	if (tmp)
		ap = ft_strjoin_free(&tmp, &ap);
	return (ap);
}
