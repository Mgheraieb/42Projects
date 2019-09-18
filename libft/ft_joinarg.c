/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:22:29 by mgheraie          #+#    #+#             */
/*   Updated: 2019/07/18 05:23:22 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_joinarg(size_t nbelem, ...)
{
	va_list		ap;
	char		*res;
	char		*tmp;
	size_t		i;

	va_start(ap, nbelem);
	i = -1;
	while (++i < nbelem)
	{
		if (!(tmp = ft_strdup(va_arg(ap, char*))))
			return (NULL);
		if (i == 0)
		{
			if (!(res = ft_strdup(tmp)))
				return (NULL);
			ft_strdel(&tmp);
		}
		else
		{
			if (!(res = ft_strjoin_free(&res, &tmp)))
				return (NULL);
		}
	}
	va_end(ap);
	return (res);
}
