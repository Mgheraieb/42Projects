/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:54 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:39:31 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtolower(char *string)
{
	unsigned int	i;

	if (string == NULL)
		return (NULL);
	i = 0;
	while (string[i])
	{
		string[i] = ft_tolower(string[i]);
		i++;
	}
	return (string);
}
