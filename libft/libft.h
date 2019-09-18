/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:02:10 by mgheraie          #+#    #+#             */
/*   Updated: 2019/07/18 05:22:17 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				ft_swapp(void *a, void *b);
char				*ft_strrev(char *str);
int					ft_strisempty(char *s);
void				ft_lstpushback(t_list **lst, t_list *add);
size_t				ft_lstlen(t_list **lst);
size_t				ft_countword(const char *s, char c);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del) (void*, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *add);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr(char *s);
void				ft_putstr_fd(char *s, int fd);
char				*ft_itoa(long int n);
char				**ft_strsplit(const char *s, char c);
char				*ft_strtrim(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(const char *s, unsigned int start, size_t stop);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strmap(const char *s, char (*f)(char));
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *str, size_t n);
void				*ft_memmove(void *dest, const void *str, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *str, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *dest, const char *src, size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *dest, const char *src);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t len);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char*));
void				ft_striteri(char *s, void (*f) (unsigned int, char*));
char				*ft_strjoin_free(char **s1, char **s2);
uintmax_t			ft_power(uintmax_t nb, int power);
char				*ft_joinchar(char *s, char c);
int					ft_nbrlen(uintmax_t nb);
char				*ft_itoa_base(uintmax_t nb, int base, char c);
void				ft_putnbr_base(unsigned int nb, unsigned int base);
void				ft_putfloat(double *nb, unsigned int i);
void				ft_putlongnbr(long int nb);
int					ft_strchri(char *str, char c);
char				*ft_itoa_base(uintmax_t nb, int base, char c);
size_t				ft_intlen(long int n);
int					ft_strichr(char *s, int c, int i);
void				ft_dstrdel(char **s);
size_t				ft_dstrlen(char **s);
int					ft_strgetlastocc(char *s, char c);
void				ft_putdstr(char **s);
char				*ft_joinarg(size_t nbelem, ...);
#endif
