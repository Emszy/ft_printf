NAME = ft_printf

FLAGS = -Wall -Wextra -Werror

SRC =	\
		ft_printf.c \
		flags.c \
		characters.c \
		strings.c \
		num.c \
		unumbers.c \
		xnumbers.c \
		onumbers.c \
		pointers.c

INPUT_OBJ =	\
		ft_printf.o \
		flags.o \
		characters.o \
		strings.o \
		num.o \
		unumbers.o \
		xnumbers.o \
		onumbers.o \
		pointers.o
		
OBJ = $(patsubst %.c,%.o,$(addprefix ./, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	make -C libft/
	gcc $(FLAGS) -I libft -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libft/ -lft

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(INPUT_OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean