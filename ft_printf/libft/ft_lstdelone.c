/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:56:05 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/13 18:10:31 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	if (!*alst || !alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)&(*alst)->content);
	ft_memdel((void**)alst);
}
