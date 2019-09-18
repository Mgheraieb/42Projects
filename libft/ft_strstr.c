/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:01:54 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/13 17:56:20 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dest, const char *src)
{
	size_t i;
	size_t j;

	if (dest == src)
		return ((char*)dest);
	i = 0;
	while (dest[i])
	{
		j = 0;
		while (src[j] == dest[i + j] && src[j])
			j++;
		if (src[j] == '\0')
			return ((char*)dest + i);
		i++;
	}
	return (NULL);
}
