/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:47:59 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/13 19:53:32 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && (s[start] == '\n' || s[start] == '\t' ||
				s[start] == ' '))
		start++;
	if (start == ft_strlen(s))
		return (ft_strdup(""));
	end = ft_strlen(s) - 1;
	while (end && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (!(res = ft_strsub(s, start, end - start + 1)))
		return (NULL);
	return (res);
}
