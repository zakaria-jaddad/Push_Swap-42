/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/24 14:19:20 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	stackclear(stack_a);
	stackclear(stack_b);
	stack_a = NULL;
	stack_b = NULL;
}

int	check_input(char *input, t_list **operations)
{
	char	*input_dup;

	if (ft_strcmp(input, "sa\n") == 0 || ft_strcmp(input, "sb\n") == 0
		|| ft_strcmp(input, "ss\n") == 0 || ft_strcmp(input, "pa\n") == 0
		|| ft_strcmp(input, "pb\n") == 0 || ft_strcmp(input, "ra\n") == 0
		|| ft_strcmp(input, "rb\n") == 0 || ft_strcmp(input, "rr\n") == 0
		|| ft_strcmp(input, "rra\n") == 0 || ft_strcmp(input, "rrb\n") == 0
		|| ft_strcmp(input, "rrr\n") == 0)
	{
		input_dup = ft_strdup(input);
		if (input_dup == NULL)
			return (0);
		ft_lstadd_back(operations, ft_lstnew(input_dup));
	}
	else
		return (0);
	return (1);
}

t_list	*get_input(t_stack **stack_a)
{
	t_list	*operations;
	char	*input;

	operations = NULL;
	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			break ;
		if (check_input(input, &operations) == 0)
		{
			operations = (ft_lstclear(&operations, free), NULL);
			*stack_a = (stackclear(stack_a), NULL);
			input = (free(input), NULL);
			(void)get_next_line(4);
			prog_error();
		}
		input = (free(input), NULL);
	}
	(void)get_next_line(4);
	return (operations);
}

int	main(int argc, char **argv)
{
	char	*elements;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*operations;

	if (--argc == 0 || ++(argv) == NULL)
		return (EXIT_SUCCESS);
	elements = join_arguments(argc, argv);
	if (elements == NULL)
		prog_error();
	stack_b = NULL;
	stack_a = parse_elements(elements);
	if (stack_a == NULL)
		prog_error();
	operations = get_input(&stack_a);
	if (operations == NULL)
		prog_error();
	sort_stack(&stack_a, &stack_b, operations);
	if (is_stack_sorted(stack_a) != 0 && stacksize(stack_b) == 0)
		return (ft_putstr_fd("OK\n", 1), free_stacks(&stack_a, &stack_b),
			ft_lstclear(&operations, free), EXIT_SUCCESS);
	return (ft_putstr_fd("KO\n", 1), free_stacks(&stack_a, &stack_b),
		ft_lstclear(&operations, free), EXIT_SUCCESS);
}
