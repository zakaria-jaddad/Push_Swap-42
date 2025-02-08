
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:32:07 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/08 19:19:34 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/libftprintf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	unsigned int	index;
	int				number;
	struct s_stack	*next;
}					t_stack;

t_stack				*parse_elements(char *elements);
t_stack				*create_stack(int *arr, int arr_size);
char				*join_arguments(int argc, char **args);
void				*free_args(char **args);
void				prog_error(void);

// ------------ utils ------------

/* is_all_digits: checks if all elements are valid digits */
int					is_all_digits(char **elements);

// ------------ stac utils ------------
void				stackadd_back(t_stack **stack, t_stack *new);
t_stack				*stack_new(int number, unsigned int index);
void				stackclear(t_stack **stack);

#endif // !PUSH_SWAP_H
