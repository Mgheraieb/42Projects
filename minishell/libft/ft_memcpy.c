/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:40 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:36:41 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*src;

	if (num != 0)
	{
		i = 0;
		dest = (unsigned char*)destination;
		src = (unsigned char*)source;
		while (i < num)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (destination);
}
