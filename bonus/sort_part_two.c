/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:37:53 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/14 11:32:43 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_element_position(t_stack *stack, int element_index)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		if (stack->index == element_index)
			return (counter);
		counter++;
		stack = stack->next;
	}
	return (-1);
}

static void	para_rrb_rb(t_stack **stack_a, t_stack **stack_b,
		int *largest_number_index, int *stack_a_bottom_index)
{
	if (*largest_number_index == *stack_a_bottom_index
		|| *stack_a_bottom_index < (*stack_b)->index)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		*stack_a_bottom_index = stacklast(*stack_a)->index;
	}
	else
	{
		if (find_element_position(*stack_b, (*stack_a)->index
				- 1) > (stacksize(*stack_b) / 2))
			rrb(stack_b);
		else
			rb(stack_b);
	}
}

void	sort_part_two(t_stack **stack_a, t_stack **stack_b)
{
	int	largest_number_index;
	int	stack_a_bottom_index;

	stack_a_bottom_index = stacklast(*stack_a)->index;
	largest_number_index = stack_a_bottom_index;
	while (*stack_b)
	{
		while ((*stack_b) && (*stack_b)->index != (*stack_a)->index - 1)
			para_rrb_rb(stack_a, stack_b, &largest_number_index,
				&stack_a_bottom_index);
		while ((*stack_b) && (*stack_b)->index == (*stack_a)->index - 1)
			pa(stack_a, stack_b);
		if (stacklast(*stack_a)->index == (*stack_a)->index - 1)
		{
			while ((*stack_a)->index - 1 == stacklast(*stack_a)->index)
			{
				rra(stack_a);
				stack_a_bottom_index = stacklast((*stack_a))->index;
			}
		}
		if (is_stack_sorted(*stack_a) && stacksize(*stack_b) == 0
			&& *stack_b == NULL)
			break ;
	}
}
