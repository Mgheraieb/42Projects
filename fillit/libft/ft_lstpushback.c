/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:56:57 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/15 10:57:24 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (!lst)
		*lst = new;
	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
	}
	tmp = new;
	free(tmp);
}
