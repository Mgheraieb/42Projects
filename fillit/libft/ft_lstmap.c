/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:57:28 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/13 18:09:27 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *s;

	if (lst)
	{
		if (!(s = (t_list*)malloc(lst->content_size)))
			return (NULL);
		s = f(lst);
		s->next = ft_lstmap(lst->next, f);
		return (s);
	}
	return (NULL);
}
