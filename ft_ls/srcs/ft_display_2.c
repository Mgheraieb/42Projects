/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 07:07:47 by araout            #+#    #+#             */
/*   Updated: 2019/03/12 19:27:37 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_gettotal(t_list *head, uint16_t flag)
{
	t_list	*curr;
	t_dir	*rep;
	int		i;

	curr = head;
	i = 0;
	while (curr && (rep = (t_dir*)curr->content))
	{
		if (flag & FLAGA)
			i += rep->blocks;
		else if (rep->name[0] != '.')
			i += rep->blocks;
		curr = curr->next;
	}
	return (i);
}

void		ft_put_lnkname(t_dir *rep)
{
	char	s[256];
	int		i;

	i = -1;
	while (++i < 256)
		s[i] = '\0';
	readlink(rep->pathname, s, 256);
	ft_printf(" ->"BLUE" %s"RESET, s);
}

void		ft_put_l(t_dir *rep, uint16_t flag)
{
	(flag & FLAGI) ? ft_printf("%d ", rep->ino) : 0;
	ft_put_mode(rep->mode, rep->type);
	if (rep->usrname != NULL && rep->grpname != NULL)
		ft_printf("%d  %s  %s  %d  ", rep->nlink, rep->usrname,
				rep->grpname, rep->size);
	ft_put_time(rep->time);
	ft_printf("  ");
	ft_put_name(rep->name, rep->type, rep->mode, flag);
	(rep->type == DT_LNK) ? ft_put_lnkname(rep) : 0;
	ft_printf("\n");
}

void		ft_putsimple(t_dir *rep, uint16_t flag, unsigned char boo)
{
	(flag & FLAGI) ? ft_printf("%d ", rep->ino) : 0;
	ft_put_name(rep->name, rep->type, rep->mode, flag);
	if (boo & TRUE)
	{
		if (flag & FLAGM)
			write(1, ",   ", 4);
		else if (flag & FLAG1)
			write(1, "\n", 1);
		else
			write(1, "   ", 3);
	}
}

void		ft_display_l(t_list *head, uint16_t flag)
{
	t_dir	*rep;
	t_list	*curr;

	curr = head;
	ft_printf("total %llu\n", ft_gettotal(head, flag));
	while (curr && (rep = (t_dir *)curr->content))
	{
		if (flag & FLAGA)
		{
			ft_put_l(rep, flag);
			(curr->next && flag & FLAGM) ? write(1, ", ", 2) : 0;
		}
		else if (!(ft_strstr(rep->pathname, "/.")))
		{
			ft_put_l(rep, flag);
			(curr->next && flag & FLAGM) ? write(1, ", ", 2) : 0;
		}
		curr = curr->next;
	}
}
