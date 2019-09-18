/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:51 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:51 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "shell.h"

int		exists(char *path);
int		is_dir(char *path);
int		is_executable(char *path);
char	*concat_env_string(char *name, char *value);
char	*get_cwd(t_shell *shell, int realloc);

#endif
