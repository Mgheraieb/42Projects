/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:01:59 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/11 11:03:03 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_lastchecksize(char *flag, char arg, char *ap)
{
	int tmp;

	if (ft_strchr(flag, '#') != NULL && ap[0] != ' ')
		ap = ft_flagtag(arg, ap);
	if (ft_strchr(flag, '0') != NULL)
	{
		if ((tmp = ft_strchri(ap, '+')) != -1)
		{
			ap[tmp] = ap[tmp - 1];
			ap[0] = '+';
		}
		else if ((tmp = ft_strchri(ap, '-')) != -1)
		{
			ap[tmp] = ap[tmp - 1];
			ap[0] = '-';
		}
	}
	return (ap);
}

char	*ft_clean(char *ap)
{
	int		chr;
	int		i;
	char	c;

	chr = ((ft_strchri(ap, '-')) != -1) ? ft_strchri(ap, '-')
		: ft_strchri(ap, '+');
	if (chr == -1)
		return (ap);
	c = ap[chr];
	ap[chr] = '0';
	i = 0;
	while (ap[i] && ap[i] == ' ')
		i++;
	ap[i] = c;
	return (ap);
}

char	*ft_flagspace(char arg, char *ap)
{
	char *tmp;

	if (arg == 'd' || arg == 'i')
	{
		if (ap[0] != '-')
		{
			tmp = ft_strdup(" ");
			ap = ft_strjoin_free(&tmp, &ap);
		}
	}
	return (ap);
}
