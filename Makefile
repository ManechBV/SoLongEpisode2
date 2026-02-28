SRCS = srcs/main.c \
		srcs/ft_error.c \
		srcs/parsing.c \
		srcs/parsing2.c \
		srcs/parsing_flood.c \
		srcs/ft_window.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = so_long
INCLUDE_DIRS = -I includes -I libft -I ft_printf -I MacroLibX/includes

all: objs libft ft_printf $(NAME)

$(NAME): mlx $(OBJS) 
	$(CC) $(OBJS) libft/libft.a ft_printf/libftprintf.a MacroLibX/libmlx.so -lSDL2 $(INCLUDE_DIRS) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@

mlx:
	make -j -C MacroLibX

objs:
	mkdir objs

libft:
	make -C libft

ft_printf:
	make -C ft_printf

re: fclean all

clean:
	rm -rf $(OBJS)
	make clean -C libft
	make clean -C ft_printf
	make clean -C MacroLibX

fclean:
	rm -rf $(NAME)
	make fclean -C libft
	make fclean -C ft_printf
	make fclean -C MacroLibX

.PHONY: all re clean fclean libft ft_printf
