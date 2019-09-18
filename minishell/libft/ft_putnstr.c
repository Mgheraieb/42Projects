/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:09 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:10 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t		ft_putnstr(char *str, size_t n)
{
	size_t i;

	if (str == NULL)
		return (ft_putnstr("(null)", n));
	i = 0;
	while (str[i] && i < n)
		i++;
	write(1, str, i);
	return (i);
}
