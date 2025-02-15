/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/15 21:28:57 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"
#include <stdio.h>
#include <stdlib.h>

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

int	main(int argc, char **argv)
{
	char	*elements;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*input;

	elements = join_arguments(--argc, ++argv);
	if (elements == NULL)
		prog_error();
	stack_b = NULL;
	stack_a = parse_elements(elements);
	if (stack_a == NULL)
		prog_error();
	if (is_stack_sorted(stack_a) == 1)
	{
		stackclear(&stack_a);
		stackclear(&stack_b);
		stack_a = NULL;
		stack_b = NULL;
		return (0);
	}
	input = NULL;
	// get input from the user
	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			break ;
		// check instructions
		if (ft_strncmp(input, "sa", 2) == 0 && (input[2] == '\n'))
			sa(&stack_a);
		else if (ft_strncmp(input, "sb", 2) == 0 && (input[2] == '\n'))
			sb(&stack_b);
		else if (ft_strncmp(input, "ss", 2) == 0 && (input[2] == '\n'))
			ss(&stack_a, &stack_b);
		else if (ft_strncmp(input, "pa", 2) == 0 && (input[2] == '\n'))
			pa(&stack_a, &stack_b);
		else if (ft_strncmp(input, "pb", 2) == 0 && (input[2] == '\n'))
			pa(&stack_b, &stack_a);
		else if (ft_strncmp(input, "ra", 2) == 0 && (input[2] == '\n'))
			ra(&stack_a);
		else if (ft_strncmp(input, "rb", 2) == 0 && (input[2] == '\n'))
			rb(&stack_b);
		else if (ft_strncmp(input, "rr", 2) == 0 && (input[2] == '\n'))
			rr(&stack_a, &stack_b);
		else if (ft_strncmp(input, "rra", 3) == 0 && (input[3] == '\n'))
			rra(&stack_a);
		else if (ft_strncmp(input, "rrb", 3) == 0 && (input[3] == '\n'))
			rrb(&stack_b);
		else if (ft_strncmp(input, "rrr", 3) == 0 && (input[3] == '\n'))
			rrr(&stack_a, &stack_b);
		else
		{
			// error
			stackclear(&stack_a);
			stackclear(&stack_b);
			stack_a = NULL;
			stack_b = NULL;
			free(input);
			input = NULL;
                        get_next_line(4);
			prog_error();
		}
		free(input);
		input = NULL;
	}
	/* printf("After\n"); */
	/* for (t_stack *head = stack_a; head != NULL; head = head->next) */
	/*         printf("%d\n", head->number); */
	/* printf("i got sa\n"); */
	sort(&stack_a, &stack_b);
	stackclear(&stack_a);
	stackclear(&stack_b);
	stack_a = NULL;
	stack_b = NULL;
	return (EXIT_SUCCESS);
}
