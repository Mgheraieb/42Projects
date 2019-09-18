/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:47:59 by mgheraie          #+#    #+#             */
/*   Updated: 2019/01/21 13:30:17 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	*ft_strtrimt(const char *s)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && s[start] == '.')
		start++;
	if (start == ft_strlen(s))
		return (ft_strdup(""));
	end = ft_strlen(s) - 1;
	while (end && (s[end] == '.'))
		end--;
	if (!(res = ft_strsub(s, start, end - start + 1)))
		return (NULL);
	return (res);
}
