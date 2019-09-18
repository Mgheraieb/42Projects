/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:53 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:54 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*output;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	output = (char*)malloc(len + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	output[len] = '\0';
	while (len--)
	{
		output[i] = s[start + i];
		i++;
	}
	return (output);
}
