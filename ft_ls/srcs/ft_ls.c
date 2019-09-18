/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:32:16 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/12 19:59:29 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_cleandir(t_dir *rep)
{
	ft_strdel(&(rep->name));
	ft_strdel(&(rep->pathname));
	free(rep);
}

void				print_dir(t_list *head, uint16_t flag, DIR *dir)
{
	ft_sort_root(&head, flag);
	ft_display_root(head, flag);
	closedir(dir);
	ft_clean(&head);
}

t_dir				*get_rep(int ac, char **av, uint16_t flag)
{
	t_dir		*rep;
	DIR			*dir;
	t_list		*head;

	dir = NULL;
	head = NULL;
	rep = NULL;
	if (*av == NULL)
		head = read_dir(".", flag, dir, NULL);
	else
	{
		while (*av)
		{
			(ac > 1) ? flag = flag | MULTIARG : 0;
			(ac == 1 && flag & MULTIARG) ? flag -= MULTIARG : 0;
			if (!(head = read_dir(*av, flag, dir, NULL)))
				ac--;
			av++;
			ac--;
		}
	}
	return (rep);
}

void				parsdir(char **av)
{
	DIR		*tmp;
	char	chk;

	chk = 0;
	while (*av)
	{
		if (!(tmp = opendir(*av)))
		{
			chk = 1;
			if (errno != 20)
			{
				perror(*av);
				g_return = 1;
			}
			else
			{
				ft_put_name(*av, DT_REG, 0, 0);
				write(1, "\n", 1);
			}
		}
		else
			closedir(tmp);
		av++;
	}
}

int					main(int ac, char **av)
{
	uint16_t	flag;
	t_dir		*rep;

	ac--;
	rep = NULL;
	av++;
	flag = getflag(av);
	if (flag == 4096)
		return (-1);
	while (*av && ft_strlen(*av) > 1 && **av == '-')
	{
		if (ft_strchr(*av, 'G') != 0)
			flag = flag | FLAGG;
		av++;
		ac--;
	}
	parsdir(av);
	rep = get_rep(ac, av, flag);
	write(1, "\n", 2);
	return (g_return);
}
