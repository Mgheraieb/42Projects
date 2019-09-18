/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:10 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:10 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t		ft_putnstr_fd(char *str, size_t n, int fd)
{
	size_t i;

	if (str == NULL)
		return (ft_putnstr_fd("(null)", n, fd));
	i = 0;
	while (str[i] && i < n)
		i++;
	write(fd, str, i);
	return (i);
}
