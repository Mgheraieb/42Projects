/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:43 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:36:44 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*destination;
	unsigned char	*source;

	if (n != 0)
	{
		if (dest < src)
			ft_memcpy(dest, src, n);
		else
		{
			destination = (unsigned char*)dest;
			source = (unsigned char*)src;
			i = n;
			while (i-- != 0)
			{
				destination[i] = source[i];
			}
		}
	}
	return (dest);
}
