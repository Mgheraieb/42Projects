# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 18:02:00 by mgheraie          #+#    #+#              #
#    Updated: 2019/06/16 01:56:57 by mgheraie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c  ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c  ft_strncat.c \
	ft_strlcat.c ft_strstr.c ft_strcmp.c ft_strchr.c ft_strrchr.c  ft_strnstr.c\
	ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_memalloc.c ft_toupper.c ft_tolower.c ft_memdel.c ft_strnew.c \
	 ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd.c ft_lstdel.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_swapp.c ft_countword.c\
	ft_lstlen.c ft_lstpushback.c ft_strrev.c ft_strisempty.c ft_strjoin_free.c \
	ft_power.c ft_joinchar.c ft_nbrlen.c ft_itoa_base.c ft_putnbr_base.c \
	ft_putfloat.c ft_putlongnbr.c ft_strchri.c ft_intlen.c printf.c  flag.c \
	converter.c convert.c ft_strichr.c ft_dstrdel.c ft_dstrlen.c \
	ft_strgetlastocc.c ft_putdstr.c ft_joinarg.c

#FLAGS = -Wall -Wextra -Werror -fsanitize=address
FLAGS = -Wall -Wextra -Werror

HEADER = libft.h
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	gcc -c $(FLAGS) $(SRC) -I $(HEADER)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
