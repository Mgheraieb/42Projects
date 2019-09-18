/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:58:58 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/07 13:22:10 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(long int nb)
{
	char		*res;
	size_t		len;
	int			size;

	len = ft_intlen(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
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
