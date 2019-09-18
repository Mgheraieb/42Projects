/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:56:31 by araout            #+#    #+#             */
/*   Updated: 2019/03/12 20:16:06 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_add_name_f(uint8_t type, uint16_t mode)
{
	if (type & DT_DIR)
		ft_printf(BLUE"/"RESET);
	else if (type & DT_FIFO)
		write(1, "|", 1);
	else if (mode & XU)
		ft_printf(RED"*"RESET);
}

int			nul_info(t_dir **rep)
{
	t_dir	*new;

	new = *rep;
	new->nlink = 0;
	new->size = 0;
	new->usrname = NULL;
	new->grpname = NULL;
	new->rec = FALSE;
	return (1);
}

void		ft_clean(t_list **lst)
{
	t_list	*tmp;
	t_list	*head;

	tmp = NULL;
	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		ft_cleandir(tmp->content);
		free(tmp);
		tmp = NULL;
	}
}
