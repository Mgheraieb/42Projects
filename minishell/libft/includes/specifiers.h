/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:08 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:09 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIERS_H
# define SPECIFIERS_H
# include "list.h"

int			parse_specifier(const char *start, t_spec **spec, int idx, int fd);
int			get_specifiers(const char *format, t_spec **spec, int fd);

#endif
