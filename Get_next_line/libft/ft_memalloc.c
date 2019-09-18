/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:24:52 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/27 22:44:54 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *str;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (str)
		ft_memset(str, '\0', size + 1);
	return (str);
}
