/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:20:37 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/11 11:19:00 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <float.h>

int		ft_skip(char *flag, char arg, char *ap);
int		ft_getwidth(char *flag, char arg, char *ap);
char	*ft_clean(char *ap);

int		ft_get_flag(const char *format, char **flag);
int		ft_printf(const char *format, ...);

int		ft_getbase(char arg);
int		ft_getlen(char *flag);
int		ft_read_flag(void *ap, char *flag);
char	*ft_redirconv(char *flag, void *ap);

char	*ft_readstr(void *ap);
char	*ft_readint(char *flag, void *ap);
char	*ft_readuint(char *flag, void *ap, char arg);
char	*ft_noarg(char *flag, char arg);
char	*ft_readchar(char *flag, void *ap);
int		ft_readfloat(double ap, char *flag);

char	*ft_structflag(char *flag, char *ap, char *tmp);
char	*ft_lastchecksize(char *flag, char arg, char *ap);
char	*ft_redirflag(char *flag, char arg, char *ap);
char	*ft_flagtag(char arg, char *ap);
char	*ft_flagsize(char *flag, char arg, char *ap, int precision);
char	*ft_flagplus(char arg, char *ap);
char	*ft_flagspace(char arg, char *ap);
char	*ft_precision(char arg, char *ap, int precision);

int		ft_isconv(char c);
int		ft_isflag(char c);
int		ft_parsingflag(char *flag);
int		ft_getprecision(char *flag);
void	ft_putspecchar(char ap);
#endif
