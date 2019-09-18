/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:44:37 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/12 20:03:27 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_puttype(uint8_t type)
{
	(type == DT_DIR || type == 0) ? ft_putchar('d') : 0;
	(type == DT_BLK) ? ft_putchar('b') : 0;
	(type == DT_CHR) ? ft_putchar('c') : 0;
	(type == DT_LNK) ? ft_putchar('l') : 0;
	(type == DT_FIFO) ? ft_putchar('p') : 0;
	(type == DT_SOCK) ? ft_putchar('s') : 0;
	(type == DT_REG) ? ft_putchar('-') : 0;
	return (1);
}

void	ft_put_mode(uint16_t mode, uint8_t type)
{
	((ft_puttype(type)) && (mode & RU)) ? write(1, "r", 1) : write(1, "-", 1);
	(mode & WU) ? write(1, "w", 1) : write(1, "-", 1);
	if (mode & XU && mode & SUID)
		write(1, "s", 1);
	else if (mode & SUID)
		write(1, "S", 1);
	else
		(mode & XU) ? write(1, "x", 1) : write(1, "-", 1);
	(mode & RG) ? write(1, "r", 1) : write(1, "-", 1);
	(mode & WG) ? write(1, "w", 1) : write(1, "-", 1);
	if (mode & SGID && mode & XG)
		write(1, "s", 1);
	else if (mode & SGID)
		write(1, "S", 1);
	else
		(mode & XG) ? write(1, "x", 1) : write(1, "-", 1);
	(mode & RO) ? write(1, "r", 1) : write(1, "-", 1);
	(mode & WO) ? write(1, "w", 1) : write(1, "-", 1);
	if ((mode & STICKY) && (mode & XO))
		write(1, "t", 1);
	else if (mode & STICKY)
		write(1, "T", 1);
	else
		(mode & XO) ? write(1, "x", 1) : write(1, "-", 1);
	ft_printf("  ");
}

void	ft_put_time(time_t time)
{
	char *ttime;

	ttime = ctime(&time);
	ttime += 4;
	write(1, ttime, ft_strlen(ttime) - 9);
}

void	ft_putcolor_name(char *name, uint8_t type, uint16_t mode, uint16_t flag)
{
	if (type == DT_DIR)
		ft_printf(BLUE"%s"RESET, name);
	else if (mode & SGID || mode & STICKY || mode & SUID || type == DT_CHR)
		ft_printf("\x1b[93;41m%s"RESET, name);
	else if (type == DT_LNK)
		ft_printf(MAG"%s"RESET, name);
	else if (mode & XU)
		ft_printf(RED"%s"RESET, name);
	else if (type == DT_REG)
		ft_printf("%s", name);
	else
		ft_printf("%s", name);
	if (flag & FLAGF)
		ft_add_name_f(type, mode);
}

void	ft_put_name(char *name, uint8_t type, uint16_t mode, uint16_t flag)
{
	if (flag & FLAGG)
	{
		ft_putcolor_name(name, type, mode, flag);
		return ;
	}
	if (type == DT_DIR)
		ft_printf("%s", name);
	else if (mode & SGID || mode & STICKY || mode & SUID || type == DT_CHR)
		ft_printf("%s", name);
	else if (type == DT_LNK)
		ft_printf("%s", name);
	else if (mode & XU)
		ft_printf("%s", name);
	else if (type == DT_REG)
		ft_printf("%s", name);
	else
		ft_printf("%s", name);
	if (flag & FLAGF)
		ft_add_name_f(type, mode);
}
