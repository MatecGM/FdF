CC = cc

#FLAGS = -Wall -Wextra -Werror

NAME = so_long

SRCS = test.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -LMacroLibX/limlx.so -lmlx -lXext -lX11

.c.o:
	$(CC) $(FLAGS) -I/usr/include -I./MacroLibX/includes -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re