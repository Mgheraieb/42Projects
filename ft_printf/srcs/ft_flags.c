/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:57:35 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/11 11:15:03 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_flagplus(char arg, char *ap)
{
	char *tmp;

	if (arg == 'd' || arg == 'i')
	{
		if (ft_strchr(ap, '-') == NULL)
		{
			tmp = ft_strdup("+");
			ap = ft_strjoin_free(&tmp, &ap);
		}
	}
	return (ap);
}

char	*ft_flagsize(char *flg, char arg, char *ap, int p)
{
	char	*res;
	char	c;
	int		i;

	i = -1;
	while (flg[++i] && ft_isdigit(flg[i]) == 0 && flg[i] != '0')
		if (flg[i] == '.')
			return (NULL);
	if (flg[i] == '\0')
		return (NULL);
	c = (flg[i] == '0') ? '0' : ' ';
	while ((c == '0') && flg[++i] && (flg[i] == '0' || ft_isdigit(flg[i]) == 0))
		;
	i = ft_atoi(&flg[i]);
	(arg != 'c' && ft_strchr(flg, '.')
	!= NULL && p < (int)ft_strlen(ap)) ? c = ' ' : 0;
	(p < i && p != 0) ? p = i - p : 0;
	(ft_strchr(flg, '0') && p > 0 && ft_strchr(ap, '-')) ? p-- : 0;
	i -= ((arg != 'c') ? ft_strlen(ap) : 0);
	i -= ft_skip(flg, arg, ap);
	res = (i <= 0) ? NULL : ft_strnew(i);
	(i > 0 && ft_strchr(flg, '-')) ? c = ' ' : 0;
	(i > 0) ? ft_memset(res, c, i) : 0;
	(i > 0 && p > 0) ? ft_memset(res, ' ', i) : 0;
	return (res);
}

char	*ft_structflag(char *flag, char *ap, char *tmp)
{
	char c;
	char a;
	char *tmpflag;

	tmpflag = flag;
	while (ft_isdigit(*flag) == 0 && ft_isflag(*flag) == -1)
		flag++;
	if (ft_isflag(*flag) == 1)
		while ((a = (*flag == '0') ? '0' : ' ') && ft_isdigit(*flag) == 0)
			flag++;
	if (*flag == '0')
		while (ft_isdigit(*flag) == 0)
			flag++;
	c = (ft_strchri(ap, 'x') == -1) ? ap[0] : 'x';
	if (ft_strchr(tmpflag, '-'))
		ap = ft_strjoin_free(&ap, &tmp);
	else if ((a == '0') && (ft_strchr(tmpflag, '+') != NULL ||
				ft_strchr(ap, '-') != NULL || c == 'x'))
	{
		ap[(ft_strchri(ap, 'x') == -1) ? 0 : ft_strchri(ap, 'x')] = tmp[0];
		(c == 'x') ? tmp[1] = 'x' : 0;
		(c != 'x') ? tmp[0] = c : 0;
	}
	(ft_strchr(tmpflag, '-') == NULL) ? ap = ft_strjoin_free(&tmp, &ap) : 0;
	return (ap);
}

char	*ft_precision(char arg, char *ap, int precision)
{
	char	*tmp;

	if (precision == 0 && ft_strcmp(ap, "0") == 0)
	{
		ft_strdel(&ap);
		ap = ft_strnew(0);
		return (ap);
	}
	(arg == 's') ? tmp = ft_strsub(ap, 0, precision) : 0;
	(arg == 's') ? ft_strdel(&ap) : 0;
	(arg == 's') ? ap = ft_strdup(tmp) : 0;
	if (arg != 's')
	{
		if (precision <= (int)ft_strlen(ap))
			return (ap);
		precision -= ft_strlen(ap);
		(ft_strchr(ap, '-')) ? precision++ : 0;
		if (!(tmp = ft_strnew(precision)))
			return (NULL);
		ft_memset(tmp, '0', precision);
		ap = ft_strjoin_free(&tmp, &ap);
	}
	if (*tmp)
		ft_strdel(&tmp);
	return (ap);
}
