# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 15:35:40 by mgheraie          #+#    #+#              #
#    Updated: 2019/01/28 15:35:41 by mgheraie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= ft_algo.c \
		  ft_verif.c \
		  ft_tools.c \
		  main.c

OBJ		= $(SRC:.c=.o)

INCLUDE	= fillit.h\
		  libft/libft.h

$(NAME): $(OBJ)
	make -C libft
	gcc -Wall -Werror -Wextra $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
