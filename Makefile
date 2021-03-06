NAME = libftprintf.a

CFLAG = -c -Wall -Werror -Wextra

SRCS = 		srcs/ft_printf.c \
			srcs/flags.c \
			srcs/characters.c \
			srcs/strings.c \
			srcs/num.c \
			srcs/unumbers.c \
			srcs/xnumbers.c \
			srcs/onumbers.c \
			srcs/pointers.c

OBJS = 		ft_printf.o \
			flags.o \
			characters.o \
			strings.o \
			num.o \
			unumbers.o \
			xnumbers.o \
			onumbers.o \
			pointers.o

LIB_OBJS = 	libft/ft_putchar.o \
			libft/ft_putstr.o \
			libft/ft_putnbr.o \
			libft/ft_strcmp.o \
			libft/ft_strlen.o \
			libft/ft_atoi.o \
			libft/ft_isalpha.o \
			libft/ft_strcpy.o \
			libft/ft_memset.o \
			libft/ft_bzero.o \
			libft/ft_memcpy.o \
			libft/ft_memccpy.o \
			libft/ft_memalloc.o \
			libft/ft_memmove.o \
			libft/ft_memchr.o \
			libft/ft_memcmp.o \
			libft/ft_strdup.o \
			libft/ft_strncpy.o \
			libft/ft_strcat.o \
			libft/ft_strncat.o \
			libft/ft_strlcat.o \
			libft/ft_strchr.o \
			libft/ft_strrchr.o \
			libft/ft_strstr.o \
			libft/ft_strnstr.o \
			libft/ft_strncmp.o \
			libft/ft_isdigit.o \
			libft/ft_isalnum.o \
			libft/ft_isascii.o \
			libft/ft_isprint.o \
			libft/ft_toupper.o \
			libft/ft_tolower.o \
			libft/ft_memdel.o \
			libft/ft_strnew.o \
			libft/ft_strdel.o \
			libft/ft_strclr.o \
			libft/ft_striter.o \
			libft/ft_striteri.o \
			libft/ft_strmap.o \
			libft/ft_strmapi.o \
			libft/ft_strequ.o \
			libft/ft_strnequ.o \
			libft/ft_strsub.o \
			libft/ft_strjoin.o \
			libft/ft_putendl.o \
			libft/ft_putchar_fd.o \
			libft/ft_putstr_fd.o \
			libft/ft_putendl_fd.o \
			libft/ft_putnbr_fd.o \
			libft/ft_strtrim.o \
			libft/ft_strsplit.o \
			libft/ft_itoa.o \
			libft/ft_isspace.o \
			libft/ft_last_word.o \
			libft/ft_isneg.o \
			libft/ft_search_and_replace.o \
			libft/ft_isupper.o \
			libft/ft_lstnew.o \
			libft/ft_lstdelone.o \
			libft/ft_lstdel.o \
			libft/ft_lstadd.o \
			libft/ft_lstiter.o \
			libft/ft_lstmap.o \
			libft/get_next_line.o
			


LIBS = libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS):
		gcc $(CFLAG) $(SRCS)
fast:
	gcc -Wall -Werror -Wextra $(SRCS) $(LIB_OBJS)
	rm -f $(OBJS)

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