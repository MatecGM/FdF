CC = cc

#FLAGS = -Wall -Wextra -Werror

NAME = fdf

SRCS = main.c\
		input.c\
		mesh.c\
		placer.c\
		parcing.c\
		mouvement.c\
		printf/ft_libft.c \
		printf/ft_printf.c \
		printf/ft_putnbr_base.c \
		printf/ft_putnbr.c \
#enlever printf

OBJS = $(SRCS:.c=.o)

MLX = MacroLibX/libmlx.so

LIBFT = libft/libft.a

all : $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) -g  $(OBJS) -o $(NAME) -lXext -lX11 $(MLX) $(LIBFT) -lSDL2 -lm

$(MLX):
	make -C MacroLibX -j

$(LIBFT):
	make -C libft -j

.c.o:
	$(CC) -g $(FLAGS) -I/usr/include -I./MacroLibX/includes -I./libft -O3 -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C MacroLibX clean
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
#make -C MacroLibX fclean

re: fclean all

.PHONY: all clean fclean re