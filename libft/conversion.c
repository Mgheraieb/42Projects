/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:07:16 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/07 03:22:30 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_is_arg(t_printf *pf)
{
	if (*pf->format == 'd' || *pf->format == 'i' || *pf->format == 'o'
			|| *pf->format == 'x' || *pf->format == 'X' || *pf->format == 'u'
			|| *pf->format == 's' || *pf->format == 'p' || *pf->format == 'c'
			|| *pf->format == 'f')
		return (1);
	return (0);
}
