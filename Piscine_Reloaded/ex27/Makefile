# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:14:21 by mgheraie          #+#    #+#              #
#    Updated: 2018/11/06 11:21:31 by mgheraie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = ft_display_file.c
OBJS = ft_display_file.o
FLAGS = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	$(FLAGS) -o $(NAME) $(SRC)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

e: fclean all
