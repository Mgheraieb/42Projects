/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:49:52 by mgheraie          #+#    #+#             */
/*   Updated: 2019/06/08 05:52:10 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	c;
	int		i;

	i = 0;
	c = src[i];
	while (n--)
	{
		if (c != '\0')
			c = src[i];
		dest[i] = c;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
