/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <mgheraie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:11:48 by mgheraie          #+#    #+#             */
/*   Updated: 2019/01/21 14:10:20 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

char	**ft_parsing(char **av);
void	ft_tabdel(char **s, char *map);
char	*ft_get_tetri(const int fd);
int		ft_sqrt(int i);
char	*ft_create_map(int i, char *res);
int		ft_verif_tetris(char **tetris);
void	ft_putit(char *s);
void	ft_remove_tetri(char *map, int nbt);
int		ft_is_placable(char *tetris, char *map, int imap);
int		ft_put_in_tab(char *tetri, char *map, int imap, int nbt);
int		ft_get_dot(char *map, int start);
int		ft_fillit(char **tetris, char *map, int imap, int nbt);
int		ft_lentab(char **str);

#endif
