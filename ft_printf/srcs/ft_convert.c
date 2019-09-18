/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:40:38 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/11 10:59:14 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_readstr(void *ap)
{
	char *res;

	res = (ap != NULL) ? ft_strdup((char*)ap) : ft_strdup("(null)");
	return (res);
}

void	ft_putspecchar(char ap)
{
	if (ap == 0)
		write(1, "", 1);
	else
		ft_putchar(ap);
}

char	*ft_readchar(char *flag, void *ap)
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

char	*ft_readint(char *flag, void *ap)
{
	char	*res;
	int		len;

	res = NULL;
	len = ft_getlen(flag);
	if (len == 1)
		res = ft_itoa((long int)ap);
	else if (len == -1)
		res = ft_itoa((short)ap);
	else if (len == -2)
		res = ft_itoa((char)ap);
	else if (len != 2)
		res = ft_itoa((int)ap);
	return (res);
}

char	*ft_readuint(char *flag, void *ap, char arg)
{
	char	*res;
	int		len;
	int		base;
	char	tmp;

	len = ft_getlen(flag);
	base = ft_getbase(arg);
	tmp = (arg == 'X') ? 'A' : 'a';
	if (len == 1 || arg == 'p')
		res = ft_itoa_base((unsigned long int)ap, base, tmp);
	else if (len == -1 && arg != 'p')
		res = ft_itoa_base((unsigned short)ap, base, tmp);
	else if (len == -2 && arg != 'p')
		res = ft_itoa_base((unsigned char)ap, base, tmp);
	else if (len == 0 && arg != 'p')
		res = ft_itoa_base((unsigned int)ap, base, tmp);
	else
		res = ft_strnew(0);
	return (res);
}
