/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:41 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:42 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*output;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	output = (char*)malloc(ft_strlen(s) + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = f(s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
