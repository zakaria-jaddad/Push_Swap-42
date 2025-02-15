/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:22:47 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/14 12:01:38 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int	min;

	if (stack == NULL)
		return (-1);
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

void	hardcoded_three_number_sort(t_stack **stack)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack)->index;
	mid = (*stack)->next->index;
	bottom = (*stack)->next->next->index;
	if (is_stack_sorted(*stack) == 0 && top > mid && top > bottom)
		ra(stack);
	top = (*stack)->index;
	mid = (*stack)->next->index;
	bottom = (*stack)->next->next->index;
	if (is_stack_sorted(*stack) == 0 && (bottom < top || bottom < mid))
		rra(stack);
	top = (*stack)->index;
	mid = (*stack)->next->index;
	bottom = (*stack)->next->next->index;
	if (is_stack_sorted(*stack) == 0 && (bottom > top || bottom > mid))
		sa(stack);
}

void	hardcoded_five_number_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	push_count;
	int	min_index;
	int	min_index_pos;

	push_count = 0;
	while (push_count < 2)
	{
		min_index = find_min_index(*stack_a);
		min_index_pos = find_element_position(*stack_a, min_index);
		if (min_index_pos > stacksize(*stack_a) / 2)
			while ((*stack_a)->index != min_index)
				rra(stack_a);
		else
			while ((*stack_a)->index != min_index)
				ra(stack_a);
		pb(stack_b, stack_a);
		push_count++;
	}
	hardcoded_three_number_sort(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
