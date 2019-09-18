/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:44:32 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:44:32 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "constants.h"

void	set_default_env(t_shell *shell, char **env)
{
	if (get_env_var("PATH", env) == NULL)
		set_env_var("PATH", DEFAULT_PATH, shell);
}
