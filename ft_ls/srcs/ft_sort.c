/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 04:34:41 by araout            #+#    #+#             */
/*   Updated: 2019/03/12 19:55:06 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_swap_n(t_list **head, int j, int i)
{
	t_list	*to_i;
	t_list	*to_j;
	void	*tmp;

	to_i = *head;
	to_j = *head;
	while (i-- > 0)
		to_i = to_i->next;
	while (j-- > 0)
		to_j = to_j->next;
	tmp = to_i->content;
	to_i->content = to_j->content;
	to_j->content = tmp;
}

static void		sort_flag_rev(t_list **head)
{
	t_list	*curr;
	t_list	*end;
	int		i;
	int		j;

	i = 0;
	j = 0;
	curr = *head;
	end = *head;
	while (end && end->next)
	{
		end = end->next;
		i++;
	}
	while (i > j)
	{
		ft_swap_n(head, i, j);
		j++;
		i--;
	}
}

int				ft_sort_root(t_list **head, uint16_t flag)
{
	*head = mergesorti(*head, compare_ascii);
	if (flag & FLAGT)
		*head = mergesorti(*head, compare_time);
	((flag & FLAGREV)) ? sort_flag_rev(head) : 0;
	return (1);
}
