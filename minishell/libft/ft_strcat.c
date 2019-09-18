/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:18 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:19 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *destination, const char *source)
{
	int i;
	int offset;

	offset = 0;
	while (destination[offset] != '\0')
		offset++;
	i = 0;
	while (source[i] != '\0')
	{
		destination[offset + i] = source[i];
		i++;
	}
	destination[offset + i] = '\0';
	return (destination);
}
