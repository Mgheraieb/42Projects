/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:12:28 by mgheraie          #+#    #+#             */
/*   Updated: 2019/01/31 19:06:33 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_free(char **s1, char **s2)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
		return ((str = ft_strdup("")));
	size = ft_strlen(*s1) + ft_strlen(*s2);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (str)
		ft_memset(str, '\0', size + 1);
	ft_strcat(str, *s1);
	free(*s1);
	ft_strcat(str, *s2);
	free(*s2);
	return (str);
}
