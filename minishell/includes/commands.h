/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:47 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:47 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include "shell.h"

typedef struct	s_builtin
{
	char	*command;
	void	(*func)(t_shell *shell, char **args);
}				t_builtin;

void			b_alias(t_shell *shell, char **args);
void			b_alias_list(t_shell *shell, char **args);
void			b_args(t_shell *shell, char **args);
void			b_cd(t_shell *shell, char **args);
void			b_doc(t_shell *shell, char **args);
void			b_echo(t_shell *shell, char **args);
void			b_env(t_shell *shell, char **args);
void			b_export(t_shell *shell, char **args);
void			b_exit(t_shell *shell, char **args);
void			b_help(t_shell *shell, char **args);
void			b_history(t_shell *shell, char **args);
void			b_log(t_shell *shell, char **args);
void			b_setenv(t_shell *shell, char **args);
void			b_source(t_shell *shell, char **args);
void			b_unalias(t_shell *shell, char **args);
void			b_unalias_all(t_shell *shell, char **args);
void			b_unsetenv(t_shell *shell, char **args);

int				exec_builtin(char *command, char **args, t_shell *shell);
int				exec_command(t_shell *shell, char **args);

void			exec_line_command(t_shell *shell, char *cmd);
void			exec_file(t_shell *shell, char *file);

void			b_export2(t_shell *shell, char *var);
void			cd(t_shell *shell, char *folder);

#endif
