# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 15:29:27 by zajaddad          #+#    #+#              #
#    Updated: 2025/02/14 19:23:25 by zajaddad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make
NAME = push_swap

SRC =	src/join_arguments.c			\
	src/push_swap.c 			\
	src/free_args.c 			\
	src/prog_error.c 			\
	src/is_all_digits.c			\
	src/parse_elements.c			\
	src/stack_utils/stackadd_back.c		\
	src/stack_utils/stackadd_front.c	\
	src/stack_utils/stackclear.c		\
	src/stack_utils/stackdelone.c		\
	src/stack_utils/stacklast.c		\
	src/stack_utils/stacknew.c		\
	src/stack_utils/create_stack.c		\
	src/stack_utils/stacksize.c		\
	src/stack_utils/is_stack_sorted.c	\
	src/operations/swap.c			\
	src/operations/push.c			\
	src/operations/rotate.c			\
	src/operations/reverse_rotate.c		\
	src/hardcoded_sort.c			\
	src/sort_part_one.c			\
	src/sort_part_two.c			\



OBJ = $(SRC:.c=.o)

INCLUDE = include/push_swap.h
INCLUDE_BONUS = include/push_swap_bonus.h

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBDIR = lib
PRINTF = $(LIBDIR)/libftprintf/
LIBFT = $(LIBDIR)/libft/

$(NAME): all

all: libftprintf libft $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lftprintf -L$(PRINTF) -lft -L$(LIBFT) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

libftprintf: 
	$(MAKE) -C $(PRINTF)

libft: 
	$(MAKE) -C $(LIBFT)

libftprintf_fclean: 
	$(MAKE) -C $(PRINTF) fclean

libft_fclean: 
	$(MAKE) -C $(LIBFT) fclean

libftprintf_clean: 
	$(MAKE) -C $(PRINTF) fclean

libft_clean: 
	$(MAKE) -C $(LIBFT) fclean

fclean: clean libftprintf_fclean libft_fclean
	rm -f $(NAME)

clean: libftprintf_clean libft_clean 
	rm -f $(OBJ)

re: fclean all

.PHONY: clean libftprintf_fclean libftprintf libft_fclean libft
