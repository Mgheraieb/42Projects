/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:37 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:37:38 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoinfree(char *source, const char *concat)
{
	char	*tmp;

	if (source == NULL)
		tmp = ft_strdup(concat);
	else if (concat != NULL)
		tmp = ft_strjoin(source, concat);
	else
		return (ft_strdup(""));
	free(source);
	return (tmp);
}

char		*ft_strjoinfree_both(char *source, char *concat)
{
	char	*tmp;

	if (source == NULL)
		tmp = ft_strdup(concat);
	else if (concat != NULL)
		tmp = ft_strjoin(source, concat);
	else
		return (ft_strdup(""));
	free(source);
	free(concat);
	return (tmp);
}

char		*ft_strjoinfree_last(const char *source, char *concat)
{
	char	*tmp;

	if (source == NULL)
		tmp = ft_strdup(concat);
	else if (concat != NULL)
		tmp = ft_strjoin(source, concat);
	else
		return (ft_strdup(""));
	free(concat);
	return (tmp);
}
