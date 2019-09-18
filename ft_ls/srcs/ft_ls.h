/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:32:42 by mgheraie          #+#    #+#             */
/*   Updated: 2019/03/12 20:03:54 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct		s_dir
{
	unsigned int	i;
	quad_t			blocks;
	char			*pathname;
	char			*name;
	ino_t			ino;
	uint8_t			type;
	uint16_t		mode;
	unsigned char	nlink;
	char			*usrname;
	char			*grpname;
	long long		size;
	time_t			time;
	char			rec;
	struct s_dir	*next;
	int				error;
}					t_dir;

# define BLUE "\e[1;36m"
# define RED "\x1B[31m"
# define RESET "\x1B[0m"
# define MAG "\x1B[35m"
# define SOD 8
# define TRUE 1
# define FALSE 0
# define XO 1
# define WO 2
# define RO 4
# define XG 8
# define WG 16
# define RG 32
# define XU 64
# define WU 128
# define RU 256
# define STICKY 512
# define SGID 1024
# define SUID 2048
# define ISREG 1
# define ISDIR 2
# define ISBLK 4
# define ISCHR 8
# define ISLNK 16
# define ISFIFO 32
# define ISSOCK 64
# define ISUNK 128
# define FLAGL 1
# define FLAGR 2
# define FLAGA 4
# define FLAGREV 8
# define FLAGT 16
# define FLAGF 32
# define FLAGC 64
# define FLAGI 128
# define FLAGU 256
# define FLAG1 512
# define FLAGM 1024
# define FLAGG 2048
# define MULTIARG 4096

void				ft_add_name_f(uint8_t type, uint16_t mode);
int					nul_info(t_dir **rep);
void				ft_clean(t_list **lst);
char				g_return;
int					ft_isflagls(char c);
void				ft_checkflag(char c, uint16_t *flag);
uint16_t			getflag(char **av);
void				*read_error(char *name);
uint8_t				ft_setmode(mode_t i);
time_t				settime(struct stat buf, uint16_t flag);
uint16_t			error_flag(char c);
DIR					*open_error(char *filename);
DIR					**open_all(char **files, int size);
DIR					*open_mydir(char *dirname);
t_list				*read_dir(char *fname, uint16_t flag, DIR *dir, t_dir *r);
t_dir				*init_lst(struct dirent *rep, char *fname, uint16_t flag);
void				ft_display_root(t_list *head, uint16_t flag);
int					ft_sort_root(t_list **head, uint16_t flag);
void				sort_flag_u(t_dir **dir);
void				ft_put_mode(uint16_t mode, uint8_t type);
void				ft_put_size(long long size);
void				ft_put_time(time_t time);
void				ft_put_name(char *name, uint8_t type,
		uint16_t mode, uint16_t flag);
void				ft_display_l(t_list *head, uint16_t flag);
t_list				*to_list(t_dir *rep);
t_dir				*get_rep(int ac, char **av, uint16_t flag);
void				ft_display_r(t_list *head, uint16_t flag);
void				ft_putsimple(t_dir *rep, uint16_t flag, unsigned char boo);
int					ft_gettotal(t_list *head, uint16_t flag);
void				ft_put_l(t_dir *rep, uint16_t flag);
void				ft_put_lnkname(t_dir *rep);
void				ft_display_simple(t_list *head, uint16_t flag);
void				ft_reput(t_list *head, uint16_t flag);
t_dir				*ft_int_rep(int ac, char **av, uint16_t flag, t_dir **rep);
void				print_dir(t_list *head, uint16_t flag, DIR *dir);
void				ft_cleandir(t_dir *rep);
t_list				*merge(t_list *a, t_list *b,
int (*cmp)(t_list *a, t_list *b), t_list *head);
t_list				*mergesorti(t_list *p, int (*cmp)(t_list *a, t_list *b));
int					compare_ascii(t_list *a, t_list *b);
int					compare_time(t_list *a, t_list *b);
#endif
