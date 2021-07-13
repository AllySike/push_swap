NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = -L libft
OPTION_LIB = -lmlx -framework OpenGL -framework AppKit -lft
OPTION = -c
LIBFT = make -C libft
SRCS =	main.c

OBJS_SRCS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME) : $(OBJS_SRCS)
		@$(CC) $(FLAGS) $(OPTION) -I./includes $(SRCS)
		@$(LIBFT)
		$(CC) $(OBJS_SRCS) -o $(NAME) $(LIB) $(OPTION_LIB)
clean:
		rm -f $(OBJS_SRCS)
		@$(LIBFT) clean
fclean: clean
		rm -f $(NAME)
		rm -f *.bmp
		@$(LIBFT) fclean
re: fclean all
.PHONY: all clean fclean re