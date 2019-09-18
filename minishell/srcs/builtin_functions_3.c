/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:29 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:29 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "utils.h"
#include "arguments.h"
#include "commands.h"
#include "constants.h"
#include "shell.h"

void	b_unalias(t_shell *shell, char **args)
{
	if (args[1] == 0)
	{
		ft_putstr_fd("Usage: unalias ALIAS\n", 2);
		return ;
	}
	if (remove_env_var(args[1], shell->alias) == 0)
		ft_printf_fd(2, "unalias: no such alias: %s\n", args[1]);
}

void	b_unalias_all(t_shell *shell, char **args)
{
	(void)args;
	ft_free_tab(shell->alias);
	shell->alias = 0;
}

void	b_source(t_shell *shell, char **args)
{
	if (args[1] == NULL)
	{
		ft_putstr_fd("source: not enough arguments\n", 2);
		return ;
	}
	exec_file(shell, args[1]);
}
