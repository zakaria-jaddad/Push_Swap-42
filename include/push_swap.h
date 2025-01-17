#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include "../lib/libft/libft.h"
#include "../lib/printf/ft_printf.h"


typedef struct s_stack {
        unsigned int index;
        int number;
        struct s_stack *next;
} t_stack;

t_stack *create_stack(int argc, char **args);
char	*join_arguments(int argc, char **args);


#endif // !PUSH_SWAP_H
