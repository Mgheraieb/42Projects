/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 07:06:12 by araout            #+#    #+#             */
/*   Updated: 2019/03/12 19:53:29 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				compare_ascii(t_list *a, t_list *b)
{
	return (ft_strcmp(((t_dir *)a->content)->pathname,
			((t_dir *)b->content)->pathname));
}

int				compare_time(t_list *a, t_list *b)
{
	int i;
	int j;

	i = ((t_dir*)a->content)->time;
	j = ((t_dir*)b->content)->time;
	if (j < i)
		return (-1);
	else if (i == j)
		return (0);
	else
		return (1);
}

t_list			*merge(t_list *a, t_list *b, int (*cmp)(t_list *a, t_list *b),
		t_list *head)
{
	t_list	**r;

	r = &head;
	if (a && b)
	{
		while (1)
		{
			if ((*cmp)(a, b) <= 0 && (*r = a))
			{
				r = &a->next;
				a = a->next;
				if (!a)
					break ;
			}
			else if ((*r = b) || 1)
			{
				r = &b->next;
				b = b->next;
				if (!b)
					break ;
			}
		}
	}
	*r = (a == NULL) ? b : a;
	return (head);
}

t_list			*mergesorti(t_list *p, int (*cmp)(t_list *a, t_list *b))
{
	t_list	*a;
	t_list	*b;
	t_list	*last;

	b = p;
	a = b;
	last = NULL;
	while (a && a->next)
	{
		last = b;
		b = b->next;
		a = a->next->next;
	}
	if (last == NULL)
		return (p);
	last->next = NULL;
	return (merge(mergesorti(p, cmp), mergesorti(b, cmp), cmp, NULL));
}
