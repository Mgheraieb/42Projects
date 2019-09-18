/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:43 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:43 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "shell.h"
#include "libft.h"
#include "commands.h"
#include "constants.h"
#include "parsing.h"

void	exec_shrc(t_shell *shell)
{
	int		fd;
	char	*buf;

	if (shell->no_shrc)
		return ;
	fd = open(SHRC_FILE, O_RDWR | O_CREAT | O_APPEND, 448);
	if (fd < 0)
	{
		ft_putstr_fd(SHELL_NAME": error: could not read shrc file "SHRC_FILE
		"\n", 2);
		return ;
	}
	buf = NULL;
	while (get_next_line(fd, &buf) == 1)
	{
		exec_line_command(shell, buf);
		ft_strdel(&buf);
	}
	ft_strdel(&buf);
	close(fd);
}
