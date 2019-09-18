/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:56 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:58 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtoupper(char *string)
{
	unsigned int	i;

	if (string == NULL)
		return (NULL);
	i = 0;
	while (string[i])
	{
		string[i] = ft_toupper(string[i]);
		i++;
	}
	return (string);
}
