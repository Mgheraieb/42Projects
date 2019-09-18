/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:26 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:27 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup_if(const char *s, int (*f)(int))
{
	int		i;
	int		len;
	char	*output;

	len = 0;
	while (s[len] && f(s[len]))
		len++;
	output = (char*)malloc(len + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = s[i];
		i++;
	}
	output[len] = '\0';
	return (output);
}
