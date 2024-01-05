CC = cc

#FLAGS = -Wall -Wextra -Werror

NAME = fdf

SRCS = main.c\
		input.c\
		mesh.c\
		placer.c\

OBJS = $(SRCS:.c=.o)
MLX = MacroLibX/libmlx.so

all : $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) -o $(NAME) -lXext -lX11 $(MLX) -lSDL2 -g -lm

$(MLX):
	make -C MacroLibX -j

.c.o:
	$(CC) $(FLAGS) -I/usr/include -I./MacroLibX/includes -O3 -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C MacroLibX clean

fclean: clean
	rm -f $(NAME)
#make -C MacroLibX fclean

re: fclean all

.PHONY: all clean fclean re