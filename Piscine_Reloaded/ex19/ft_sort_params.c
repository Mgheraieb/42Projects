/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:14:54 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/06 12:20:39 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	if (*str != '\0')
		ft_putchar(*str);
	if (*str++ != '\0')
		ft_putstr(str++);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**ft_sort_params(char **av)
{
	int		i;
	int		j;
	char	*swap;

	swap = NULL;
	i = 1;
	while (av[i] != '\0')
	{
		j = 1;
		while (av[j] != '\0')
		{
			if (ft_strcmp(av[i], av[j]) < 0 && i != j)
			{
				swap = av[j];
				av[j] = av[i];
				av[i] = swap;
			}
			j++;
		}
		i++;
	}
	return (av);
}

int		main(int ac, char **av)
{
	char	**res;
	int		i;

	if (ac == 1)
		return (0);
	res = ft_sort_params(av);
	i = 1;
	while (res[i] != '\0')
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
