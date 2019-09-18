/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:52:11 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/27 22:46:52 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnew(size_t len)
{
	char *s;

	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s)
		ft_memset(s, '\0', len + 1);
	return (s);
}
