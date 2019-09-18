/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_memory_unsigned_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:38:13 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:38:13 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char		read_uchar(void *n)
{
	return (*(unsigned char*)n);
}

unsigned short		read_ushort(void *n)
{
	return (*(unsigned short*)n);
}

unsigned int		read_uint(void *n)
{
	return (*(unsigned int*)n);
}

unsigned long		read_ulong(void *n)
{
	return (*(unsigned long*)n);
}

unsigned long long	read_ullong(void *n)
{
	return (*(unsigned long long*)n);
}
