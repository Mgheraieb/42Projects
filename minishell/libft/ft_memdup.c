/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:43 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:36:43 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void					*ft_memdup(const void *src, size_t size)
{
	char	*out;

	if (size == 0 || (out = malloc(size)) == 0)
		return (NULL);
	ft_memcpy(out, src, size);
	return (out);
}
