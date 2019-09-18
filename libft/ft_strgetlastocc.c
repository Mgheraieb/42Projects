/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgetlastocc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 02:41:49 by mgheraie          #+#    #+#             */
/*   Updated: 2019/06/21 04:05:26 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strgetlastocc(char *s, char c)
{
	int i;
	int save;

	save = -1;
	i = -1;
	while (s[i])
	{
		if (s[i] == c)
			save = i;
		i++;
	}
	return (save);
}
