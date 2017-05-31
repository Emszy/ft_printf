NAME = libftprintf.a

CFLAG = -c -Wall -Werror -Wextra

SRCS = 		ft_printf.c \
		flags.c \
		characters.c \
		strings.c \
		num.c \
		unumbers.c \
		xnumbers.c \
		onumbers.c \
		pointers.c

OBJS = $(SRCS:.c=.o)

LIBS = libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS):
		gcc $(CFLAG) $(SRCS)

$(LIB_OBJS):
		$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIB_OBJS)
	ar rcs $(NAME) $(LIB_OBJS) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean

re: fclean all