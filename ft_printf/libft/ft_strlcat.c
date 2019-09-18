/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:54:58 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/13 17:55:59 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int f;

	i = 0;
	j = 0;
	f = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (size <= i)
	{
		j += size;
		return (j);
	}
	else
	{
		j += i;
		while (src[f] && i < size - 1)
			dest[i++] = src[f++];
		dest[i] = '\0';
	}
	return (j);
}
