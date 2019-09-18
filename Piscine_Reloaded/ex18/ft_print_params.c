/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:06:48 by mgheraie          #+#    #+#             */
/*   Updated: 2018/11/05 17:14:29 by mgheraie         ###   ########.fr       */
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

void	ft_print_params(char **av)
{
	int i;

	i = 1;
	while (av[i] != '\0')
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	ft_print_params(av);
	return (0);
}
