/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:58 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:59 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char			*output;
	unsigned int	start;
	unsigned int	end;

	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	while (is_space(s[start]))
		start++;
	end = ft_strlen(s);
	if (end - 1 > start)
		end--;
	while (end > start && is_space(s[end]))
		end--;
	output = (char*)malloc(end - start + 2);
	if (output == NULL)
		return (NULL);
	output[end - start + 1] = '\0';
	return (ft_memcpy(output, s + start, end - start + 1));
}
