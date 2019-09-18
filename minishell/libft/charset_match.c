/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charset_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:19 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:36:20 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		charset_match(char *charset, char *str)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (charset[i] && charset[i] == *str)
			++i;
		if (charset[i] != '\0')
			return (0);
		++str;
	}
	return (1);
}

int		charset_unmatch(char *charset, char *str)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (charset[i] && charset[i] != *str)
			++i;
		if (charset[i] != '\0')
			return (0);
		++str;
	}
	return (1);
}
