/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:13 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:13 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putstr_fd(char const *s, int fd)
{
	size_t i;

	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}
