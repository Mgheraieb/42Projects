/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:15 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:16 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int newsize)
{
	char *output;

	output = ft_strnew(newsize);
	if (output)
		ft_strlcpy(output, str, newsize + 1);
	ft_strdel(&str);
	return (output);
}
