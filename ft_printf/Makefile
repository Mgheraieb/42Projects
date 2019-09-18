# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 18:46:37 by rsaleh            #+#    #+#              #
#    Updated: 2019/02/11 11:03:24 by mgheraie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
OBJDIR	=	obj/
SRCDIR	=	srcs/
FILES	=	ft_printf.c \
			ft_flags.c \
			ft_convert.c \
			ft_parsing.c \
			ft_tools.c \
			ft_add.c \
			ft_add2.c
INCLUDE	=	includes/
SRC		=	$(addprefix $(SRCDIR), $(FILES))
OBJ		=	$(addprefix $(OBJDIR), $(patsubst %.c, %.o, $(notdir $(FILES))))

VPATH	= 	$(shell find $(SRCDIR) -type d)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@cd $(OBJDIR) && ar -x ../libft/libft.a && ar -rc ../$(NAME) *.o
	@ranlib $(NAME)
	@printf "$@ has been created\n"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@gcc -o $@ -c $< $(CFLAGS) -I $(INCLUDE)

clean:
	@make clean -C libft/
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all
