# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:26:48 by mgheraie          #+#    #+#              #
#    Updated: 2018/11/06 12:40:35 by mgheraie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./srcs/
OBJS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
FLAGS = -Wall -Wextra -Werror
HEADER = ./includes/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)ft_putchar.c -I $(HEADER)
	gcc $(FLAGS) -c $(SRC)ft_putstr.c -I $(HEADER)
	gcc $(FLAGS) -c $(SRC)ft_strcmp.c -I $(HEADER)
	gcc $(FLAGS) -c $(SRC)ft_strlen.c -I $(HEADER)
	gcc $(FLAGS) -c $(SRC)ft_swap.c -I $(HEADER)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
