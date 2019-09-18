/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:36:45 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/15 11:02:35 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_ok(const char *s)
{
	if (!s)
		return (0);
	return (1);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	k;

	if (ft_is_ok(s) == 0)
		return (NULL);
	if (ft_countword(s, c) == 0)
		return (ft_memalloc(sizeof(char*)));
	if (!(res = ft_memalloc(sizeof(char*) * ft_countword(s, c) + 1)))
		return (NULL);
	j = 0;
	k = 0;
	while (k < ft_countword(s, c) && s[i = j])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		if (!(res[k++] = ft_strsub(s, i, j - i)))
			return (NULL);
	}
	res[k] = 0;
	return (res);
}
