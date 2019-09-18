NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror

HEADERS = 	srcs/ft_ls.h\
			libft/libft.h\

LIB = libft/

SOURCES = 	srcs/dir.c\
			srcs/error.c\
			srcs/ft_ls.c\
			srcs/ft_struct.c\
			srcs/ft_utils.c\
			srcs/ft_display.c\
			srcs/ft_display_var.c\
			srcs/ft_sort.c\
			srcs/ft_sort_2.c\
			srcs/ft_display_2.c\
			srcs/ft_misc.c\

OBJECT = $(SOURCES:.c=.o)

$(NAME): $(LIB) $(OBJECT)
		make -C libft/
		gcc -o $(NAME) $(CFLAGS) $(OBJECT) libft/libft.a -L./libft

all: $(NAME)

clean:
		rm -rf $(OBJECT)
		make -C libft clean

fclean: clean
		rm -rf $(NAME)
		make -C libft fclean

re: fclean all
