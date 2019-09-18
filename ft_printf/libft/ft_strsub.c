/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:36:32 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/13 19:19:35 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	return (res);
}
