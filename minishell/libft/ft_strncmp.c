/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:45 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:45 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned int i;

	i = 0;
	while ((unsigned int)(str1[i]) && i < num &&
			(unsigned int)(str1[i]) == (unsigned int)(str2[i]))
		i++;
	if (i == num)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
