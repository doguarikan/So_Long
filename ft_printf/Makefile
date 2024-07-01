SRC = ft_printf.c ft_put.c ft_put2.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJC = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJC) 
	ar -rc $(NAME) $(OBJC)

clean :	 
	$(RM) $(OBJC)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re