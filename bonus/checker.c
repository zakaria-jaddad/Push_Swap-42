/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/16 18:37:33 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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

int	check_input(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		pa(stack_b, stack_a);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	get_check_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			break ;
		if (check_input(input, stack_a, stack_b) == 0)
		{
			free_stacks(stack_a, stack_b);
			input = (free(input), NULL);
			(void)get_next_line(4);
			prog_error();
		}
		input = (free(input), NULL);
	}
	(void)get_next_line(4);
}

int	main(int argc, char **argv)
{
	char	*elements;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (--argc == 0 || ++(*argv) == NULL)
		return (EXIT_SUCCESS);
	elements = join_arguments(argc, argv);
	if (elements == NULL)
		prog_error();
	stack_b = NULL;
	stack_a = parse_elements(elements);
	if (stack_a == NULL)
		prog_error();
	if (is_stack_sorted(stack_a) == 1)
		return (free_stacks(&stack_a, &stack_b), 0);
	get_check_input(&stack_a, &stack_b);
	if (is_stack_sorted(stack_a) != 0 && stacksize(stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
