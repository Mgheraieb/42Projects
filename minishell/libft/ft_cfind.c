/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:25 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:36:26 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_cfind(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c ? i : -1);
}

int		ft_rcfind(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
