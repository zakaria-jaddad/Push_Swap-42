SRC = ft_printf.c		\
      ft_puthex.c		\
      ft_putnbr.c		\
      ft_putstr.c		\
      ft_putchar.c		\
      ft_putaddress.c		\
      ft_put_unsigned_nbr.c	\
      ft_strlen.c		\

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
INCLUDE = ft_printf.h

CC = cc
AR = ar -rcs 

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME) 

re: fclean $(NAME)

.PHONY: clean
