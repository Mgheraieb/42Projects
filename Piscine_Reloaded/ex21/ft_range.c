/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:51:23 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/06 12:22:04 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		*ft_intdup(int tall)
{
	int *tab;

	tab = (int *)malloc(sizeof(int) * tall);
	return (tab);
}

int		*ft_range(int min, int max)
{
	int *res;
	int i;

	if (min >= max)
		return (NULL);
	res = ft_intdup(max - min);
	i = 0;
	while (min <= max)
	{
		res[i] = min;
		min++;
		i++;
	}
	return (res);
}
