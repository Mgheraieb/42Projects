/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:24 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:24 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int start, int end)
{
	int		len;

	if (str == NULL || start < 0 || end <= start)
		return (NULL);
	len = ft_strlen(str);
	if (start >= len || end > len)
		return (NULL);
	ft_strcpy(str + start, str + end);
	return (str);
}
