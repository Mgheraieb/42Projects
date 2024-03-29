/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:09 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:09 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define OPTIONS ("cCsSpdDioOuUxXfFbr")
# include "specifiers.h"

int		is_option(char c);
int		search_reverse(char *str, char c, int start);
int		flag(int nbr, int flags);
int		is_valid_size_flag(char c);
int		charset_match_c(char *s, char c);
int		is_printable(int print, t_spec *spec, int *maxlen);

#endif
