/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouicho <amouicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:25:35 by amouicho          #+#    #+#             */
/*   Updated: 2018/11/15 12:25:51 by amouicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	z;

	z = 0;
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (s)
	{
		while (z < len)
			str[z++] = s[start++];
		str[z] = '\0';
	}
	return (str);
}
