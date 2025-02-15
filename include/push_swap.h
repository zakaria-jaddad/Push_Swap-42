/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:21:51 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/15 16:26:18 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				prog_error(void);

// ------------ sort ------------
void				sort_part_one(t_stack **stack_a, t_stack **stack_b);
void				sort_part_two(t_stack **stack_a, t_stack **stack_b);
void				hardcoded_five_number_sort(t_stack **stack_a,
						t_stack **stack_b);
void				hardcoded_three_number_sort(t_stack **stack);
int					find_element_position(t_stack *stack, int element_index);

// ------------ stack utils ------------
void				stackadd_front(t_stack **stack, t_stack *new);
void				stackadd_back(t_stack **stack, t_stack *new);
void				stackclear(t_stack **stack);
void				stackdelone(t_stack *node);
t_stack				*stacknew(int number, int index);
t_stack				*stacklast(t_stack *stack);
t_stack				*create_stack(int *arr, int arr_size);
int					stacksize(t_stack *stack);
int					is_stack_sorted(t_stack *stack);

// ------------ stack operations ------------
void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_b, t_stack **stack_a);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// ------------ input parsing ------------
t_stack				*parse_elements(char *elements);
char				*join_arguments(int argc, char **args);
void				*free_args(char **args);
int					is_all_digits(char **elements);

#endif // !PUSH_SWAP_H
