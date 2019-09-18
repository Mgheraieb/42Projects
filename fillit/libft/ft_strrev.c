/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 03:07:12 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/15 10:58:07 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	size_t	l;
	char	*t;

	if (!(t = ft_strnew(ft_strlen(str))))
		return (NULL);
	l = ft_strlen(str);
	i = 0;
	while (l--)
	{
		t[i++] = str[l];
	}
	t[i] = '\0';
	return (t);
}
