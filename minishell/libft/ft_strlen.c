/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:40 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:40 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *s)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t			ft_strclen(const char *s, char c)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}
