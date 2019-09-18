/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:23:32 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/13 19:07:09 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *s1;
	char *s2;

	s1 = (char*)dest;
	s2 = (char*)src;
	while (n--)
	{
		*s1++ = *s2++;
	}
	return (dest);
}
