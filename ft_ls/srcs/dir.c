/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 01:46:57 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/12 19:49:10 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR				*open_dir(char *name)
{
	DIR			*dir;

	if (!(dir = opendir(name)))
	{
		g_return = 1;
		return (NULL);
	}
	return (dir);
}

t_list			*create_elem(t_dir *dir)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = (void*)dir;
	new->content_size = SOD;
	new->next = NULL;
	return (new);
}

t_list			*new_elem(t_dir *dir, t_list **head)
{
	t_list	*lst;

	if (!(*head))
		*head = create_elem(dir);
	else
	{
		lst = *head;
		while (lst->next)
			lst = lst->next;
		if (!(lst->next = create_elem(dir)))
			return (NULL);
	}
	return (*head);
}

t_list			*read_dir(char *name, uint16_t flag, DIR *dir, t_dir *r)
{
	DIR				*tmp;
	struct dirent	*open_rep;
	t_list			*head;

	head = NULL;
	if (!(dir = open_dir(name)))
		return (NULL);
	(flag & MULTIARG) ? ft_printf("%s:\n", name) : 0;
	while ((open_rep = readdir(dir)))
	{
		if (!(tmp = opendir(open_rep->d_name))
				&& errno == EACCES && (!(flag & FLAGI)) && !(flag & FLAGL))
			perror(open_rep->d_name);
		else
		{
			if (!(r = init_lst(open_rep, name, flag)))
				return (NULL);
			if (!(head = new_elem(r, &head)))
				return (NULL);
		}
		(tmp) ? closedir(tmp) : 0;
	}
	print_dir(head, flag, dir);
	(flag & MULTIARG) ? ft_printf("\n\n") : 0;
	return (head);
}
