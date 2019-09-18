/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:46 by mgheraie          #+#    #+#             */
/*   Updated: 2019/04/04 00:36:47 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_power(int nb, int power)
{
	long	result;

	result = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
