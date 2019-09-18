/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_memory_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:38:12 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:38:12 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		read_char(void *n)
{
	return (*(char*)n);
}

short		read_short(void *n)
{
	return (*(short*)n);
}

int			read_int(void *n)
{
	return (*(int*)n);
}

long		read_long(void *n)
{
	return (*(long*)n);
}

long long	read_llong(void *n)
{
	return (*(long long*)n);
}
