NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = -L libft
OPTION = -c
LIBFT = make -C libft
SRCS =	main.c \
		push_swap_helpers.c \
		reverse_rotate_operations.c \
		rotate_operations.c \
		swap_push_operations.c \
		push_b_from_a.c \
		push_a_from_b.c \
		arg_handler.c \
		parser.c

OBJS_SRCS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME) : $(OBJS_SRCS)
		@$(CC) $(FLAGS) $(OPTION) -I./includes $(SRCS)
		@$(LIBFT)
		$(CC) $(OBJS_SRCS) -o $(NAME) $(LIB)
clean:
		rm -f $(OBJS_SRCS)
		@$(LIBFT) clean
fclean: clean
		rm -f $(NAME)
		rm -f *.bmp
		@$(LIBFT) fclean
re: fclean all
.PHONY: all clean fclean re
