/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:26:45 by araout            #+#    #+#             */
/*   Updated: 2019/03/12 19:49:22 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_display_simple(t_list *head, uint16_t flag)
{
	t_dir	*rep;
	t_list	*curr;

	curr = head;
	while (curr && (rep = (t_dir *)curr->content))
	{
		if (flag & FLAGA)
			ft_putsimple(rep, flag, (curr->next) ? TRUE : FALSE);
		else if (rep->name[0] != '.')
			ft_putsimple(rep, flag, (curr->next) ? TRUE : FALSE);
		curr = curr->next;
	}
}

void		ft_display_r(t_list *head, uint16_t flag)
{
	t_list	*curr;
	t_dir	*tmp;

	if (flag & FLAGL && !(flag & FLAGM))
		ft_display_l(head, flag);
	else
		ft_display_simple(head, flag);
	curr = head;
	while (curr)
	{
		tmp = curr->content;
		if (tmp->rec == TRUE)
		{
			ft_printf("\n\n%s:\n", tmp->pathname);
			read_dir(tmp->pathname, flag, NULL, NULL);
		}
		curr = curr->next;
	}
}

void		ft_display_root(t_list *head, uint16_t flag)
{
	if (flag & FLAGR && flag & FLAGL)
		ft_display_r(head, flag);
	else if (flag & FLAGR)
		ft_display_r(head, flag);
	else if (flag & FLAGL && !(flag & FLAGM))
		ft_display_l(head, flag);
	else
		ft_display_simple(head, flag);
}
