/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:33:13 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/12 20:02:31 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			get_info(t_dir **repe, char *s, uint16_t flag)
{
	t_dir			*new;
	struct passwd	*usr;
	struct group	*grp;
	struct stat		buf;
	char			check;

	new = *repe;
	if ((check = (new->type != DT_LNK)))
		stat(s, &buf);
	else
		lstat(s, &buf);
	if (check == -1)
		return (-1);
	new->blocks = buf.st_blocks;
	new->mode = buf.st_mode;
	new->time = settime(buf, flag);
	if (!(flag & FLAGL))
		return (nul_info(repe));
	new->nlink = buf.st_nlink;
	new->size = buf.st_size;
	usr = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);
	new->usrname = (usr) ? usr->pw_name : ft_itoa(buf.st_uid);
	new->grpname = (grp) ? grp->gr_name : ft_itoa(buf.st_gid);
	return (1);
}

int					ft_add_rec(t_list **head, char *name)
{
	t_list		*new;
	t_list		*curr;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (-1);
	new->content = name;
	new->content_size = sizeof(name);
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (1);
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (1);
}

t_list				*set_rec(char *directory)
{
	DIR				*dir;
	struct dirent	*rep;
	char			*tmp;
	char			*s;
	t_list			*head;

	if (!(dir = opendir(directory)))
		return (NULL);
	while ((rep = readdir(dir)))
	{
		if (ft_strcmp(rep->d_name, ".") != 0
				&& ft_strcmp(rep->d_name, "..") != 0)
		{
			if (!(s = ft_strjoin(directory, "/")))
				return (NULL);
			if (!(tmp = ft_strdup(rep->d_name)))
				return (NULL);
			if (!(s = ft_strjoin(s, tmp)))
				return (NULL);
			ft_add_rec(&head, s);
			ft_strdel(&tmp);
		}
	}
	closedir(dir);
	return (head);
}

mode_t				ft_setname(char *name)
{
	struct stat		buf;

	stat(name, &buf);
	if (S_ISREG(buf.st_mode))
		return (DT_REG);
	else if (S_ISDIR(buf.st_mode))
		return (DT_DIR);
	else if (S_ISCHR(buf.st_mode))
		return (DT_CHR);
	else if (S_ISBLK(buf.st_mode))
		return (DT_BLK);
	else if (S_ISFIFO(buf.st_mode))
		return (DT_FIFO);
	else if (S_ISLNK(buf.st_mode))
		return (DT_LNK);
	else if (S_ISSOCK(buf.st_mode))
		return (DT_SOCK);
	return (0);
}

t_dir				*init_lst(struct dirent *rep, char *filename, uint16_t flag)
{
	t_dir	*new;
	char	*s;
	char	*tmp;

	if (!(new = (t_dir *)ft_memalloc(sizeof(t_dir))))
		return (NULL);
	if (!(new->name = ft_strdup(rep->d_name)))
		return (NULL);
	new->ino = rep->d_ino;
	if (!(s = ft_strjoin(filename, "/")))
		return (NULL);
	tmp = s;
	if (!(s = ft_strjoin(s, rep->d_name)))
		return (NULL);
	ft_memdel((void *)&tmp);
	new->pathname = s;
	new->type = (rep->d_type == 0) ? ft_setname(new->pathname) : rep->d_type;
	if (!get_info(&new, s, flag))
		return (NULL);
	if (flag & FLAGR && new->type == DT_DIR && ft_strcmp(new->name, ".") != 0
			&& ft_strcmp(new->name, "..") != 0)
		new->rec = TRUE;
	return (new);
}
