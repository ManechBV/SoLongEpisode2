SRCS = 	ft_printf.c \
		ft_printstr.c \
		ft_printint.c \
		ft_printuint.c \
		ft_printhex.c \
		ft_printptr.c

CC = cc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	cp ../libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS) -I../libft

re:	fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean
