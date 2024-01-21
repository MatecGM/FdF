CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_libft.c\
		ft_putnbr.c\
		ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
