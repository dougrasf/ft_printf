FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = \
			ft_printf.c \
			ft_printf_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	cc $(FLAG) -c $< -o $@

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re