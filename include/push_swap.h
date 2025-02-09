
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:32:07 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/09 15:14:01 by zajaddad         ###   ########.fr       */
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

void				prog_error(void);

// ------------ stack utils ------------
void				stackadd_back(t_stack **stack, t_stack *new);
void				stackclear(t_stack **stack);
void				stackdelone(t_stack *node);
t_stack				*stacknew(int number, unsigned int index);
t_stack				*stacklast(t_stack *stack);
t_stack				*create_stack(int *arr, int arr_size);

// ------------ input parsing ------------
t_stack				*parse_elements(char *elements);
char				*join_arguments(int argc, char **args);
void				*free_args(char **args);
int				is_all_digits(char **elements);

#endif // !PUSH_SWAP_H
