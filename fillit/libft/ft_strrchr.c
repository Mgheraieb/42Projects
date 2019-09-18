/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:16:38 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/08 19:31:45 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t tmp;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] == c)
			tmp = i + 1;
		i++;
	}
	if (s[i] == c)
		return ((char*)s + i);
	if (tmp != 0)
		return ((char*)s + tmp - 1);
	return (NULL);
}
