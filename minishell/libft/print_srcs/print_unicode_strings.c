/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode_strings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:19 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:20 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"
#include "libft.h"
#include "function_pointers.h"
#include <stdarg.h>

int		print_unicode_string(t_spec *spec, va_list *args)
{
	int		len;
	int		prnt_cnt;
	int		*string;

	prnt_cnt = 0;
	string = va_arg(*args, int*);
	len = ft_strlen_uni(string);
	if (string == 0)
		len = 6;
	if (spec->maxlen != 0 && ft_atoi(spec->maxlen) < len)
		len = ft_atoi(spec->maxlen);
	get_padding(spec, len);
	prnt_cnt += print_padding(spec);
	prnt_cnt += ft_putnstr_uni_fd(string, len, spec->fd);
	prnt_cnt += ft_print_char_fd(' ', spec->pad_right, spec->fd);
	return (prnt_cnt);
}
