/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:58:58 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/13 19:51:22 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long int n)
{
	int i;

	i = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char		*res;
	size_t		len;
	int			size;
	long int	nb;

	nb = n;
	len = ft_intlen(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
	}
	size = (nb < 0) ? 1 : 0;
	nb = (nb < 0) ? -nb : nb;
	len--;
	while ((int)len >= size)
	{
		res[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
