/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/16 19:00:39 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) == 2)
		return ((void)sa(stack_a));
	if (stacksize(*stack_a) == 3)
		return ((void)hardcoded_three_number_sort(stack_a));
	if (stacksize(*stack_a) == 5)
		return ((void)hardcoded_five_number_sort(stack_a, stack_b));
	sort_part_one(stack_a, stack_b);
	hardcoded_three_number_sort(stack_a);
	sort_part_two(stack_a, stack_b);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	stackclear(stack_a);
	stackclear(stack_b);
	stack_a = NULL;
	stack_b = NULL;
}

int	main(int argc, char **argv)
{
	char	*elements;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (--argc == 0 || ++(argv) == NULL)
		return (EXIT_SUCCESS);
	elements = join_arguments(argc, argv);
	if (elements == NULL)
		prog_error();
	stack_b = NULL;
	stack_a = parse_elements(elements);
	if (stack_a == NULL)
		prog_error();
	if (is_stack_sorted(stack_a) == 1)
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	sort(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
