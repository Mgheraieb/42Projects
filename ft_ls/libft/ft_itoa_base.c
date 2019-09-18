/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 14:17:56 by mgheraie          #+#    #+#             */
/*   Updated: 2018/12/29 14:18:12 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t nb, int base, char c)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 1;
	while (ft_power(base, i) - 1 < nb)
		i++;
	ret = ft_strnew(i);
	while (i-- > 0)
	{
		ret[i] = (nb % base) + (nb % base > 9 ? c - 10 : '0');
		nb /= base;
	}
	if (*ret == '0' && ret[1])
	{
		tmp = ret;
		while (*ret == '0')
			ret++;
		ret = ft_strdup(ret);
		free(tmp);
	}
	return (ret);
}
