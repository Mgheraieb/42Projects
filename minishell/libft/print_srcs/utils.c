/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:23 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:25 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

int		charset_match_c(char *s, char c)
{
	while (*s != 0)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int		is_option(char c)
{
	return (charset_match_c(OPTIONS, c) == 1);
}

int		flag(int nbr, int flags)
{
	return ((nbr & flags) == flags);
}

int		search_reverse(char *str, char c, int start)
{
	while (start >= 0)
	{
		if (str[start] == c)
			return (start);
		start--;
	}
	return (-1);
}

int		is_printable(int print, t_spec *spec, int *maxlen)
{
	if (ft_atoi(spec->maxlen) == 0 && spec->option == 'p' && !(*maxlen = 0))
		return (0);
	return (print);
}
