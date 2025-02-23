# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 15:29:27 by zajaddad          #+#    #+#              #
#    Updated: 2025/02/23 17:47:04 by zajaddad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make

MSRC =	mandatory/join_arguments.c				\
		mandatory/push_swap.c 					\
		mandatory/free_args.c 					\
		mandatory/prog_error.c 					\
		mandatory/is_all_digits.c				\
		mandatory/parse_elements.c				\
		mandatory/stack_utils/stackadd_back.c	\
		mandatory/stack_utils/stackadd_front.c	\
		mandatory/stack_utils/stackclear.c		\
		mandatory/stack_utils/stackdelone.c		\
		mandatory/stack_utils/stacklast.c		\
		mandatory/stack_utils/stacknew.c		\
		mandatory/stack_utils/create_stack.c	\
		mandatory/stack_utils/stacksize.c		\
		mandatory/stack_utils/is_stack_sorted.c	\
		mandatory/operations/swap.c				\
		mandatory/operations/push.c				\
		mandatory/operations/rotate.c			\
		mandatory/operations/reverse_rotate.c	\
		mandatory/hardcoded_sort.c				\
		mandatory/sort_part_one.c				\
		mandatory/sort_part_two.c				\

BSRC =	bonus/join_arguments_bonus.c				\
		bonus/checker_bonus.c 					\
		bonus/free_args_bonus.c 					\
		bonus/prog_error_bonus.c 					\
		bonus/is_all_digits_bonus.c				\
		bonus/parse_elements_bonus.c				\
		bonus/stack_utils/stackadd_back_bonus.c	\
		bonus/stack_utils/stackadd_front_bonus.c	\
		bonus/stack_utils/stackclear_bonus.c		\
		bonus/stack_utils/stackdelone_bonus.c		\
		bonus/stack_utils/stacklast_bonus.c		\
		bonus/stack_utils/stacknew_bonus.c		\
		bonus/stack_utils/create_stack_bonus.c	\
		bonus/stack_utils/stacksize_bonus.c		\
		bonus/stack_utils/is_stack_sorted_bonus.c	\
		bonus/operations/swap_bonus.c			\
		bonus/operations/push_bonus.c			\
		bonus/operations/rotate_bonus.c			\
		bonus/operations/reverse_rotate_bonus.c	\
		bonus/get_next_line_bonus.c				\
		bonus/checker_bonus_utils.c				\
		bonus/ft_strcmp_bonus.c				\


NAME = push_swap
BONUS_NAME = checker

MOBJ = $(MSRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

INCLUDE = include/push_swap.h lib/libft/libft.h
INCLUDE_BONUS = include/push_swap_bonus.h lib/libft/libft.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBDIR = lib
LIBFT = $(LIBDIR)/libft/

$(NAME): all

all: libft $(MOBJ)
	$(CC) $(CFLAGS) $(MOBJ) -lft -L$(LIBFT) -o $(NAME)

bonus: libft libft_bonus $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -lft -L$(LIBFT) -o $(BONUS_NAME)

$(MOBJ): %.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(BOBJ): %.o: %.c $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

libft: 
	$(MAKE) -C $(LIBFT)

libft_bonus: 
	$(MAKE) -C $(LIBFT) bonus

libft_clean: 
	$(MAKE) -C $(LIBFT) fclean

libft_fclean: 
	$(MAKE) -C $(LIBFT) fclean

fclean: clean libft_fclean
	rm -f $(NAME) $(BONUS_NAME)

clean:  libft_clean 
	rm -f $(MOBJ) $(BOBJ) 

re: fclean all

.PHONY: libft_fclean libft_clean libft libft_bonus
