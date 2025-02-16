/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:33:52 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/13 13:35:09 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	update_pivotes(int *last_pivot_one, int *pivot_one, int *pivot_two,
		t_stack **stack_a)
{
	*last_pivot_one = *pivot_one;
	*pivot_one += stacksize(*stack_a) / 3;
	*pivot_two = *last_pivot_one + (stacksize(*stack_a) / 6);
}

void	sort_part_one(t_stack **stack_a, t_stack **stack_b)
{
	int	last_pivot_one;
	int	pivot_one;
	int	pivot_two;

	last_pivot_one = -1;
	pivot_one = stacksize(*stack_a) / 3;
	pivot_two = stacksize(*stack_a) / 6;
	while (stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->index < pivot_one)
		{
			pb(stack_b, stack_a);
			if (stacksize(*stack_b) > 1)
				if ((*stack_b)->index >= last_pivot_one
					&& (*stack_b)->index <= pivot_two)
					rb(stack_b);
			if (stacksize(*stack_b) == pivot_one)
				update_pivotes(&last_pivot_one, &pivot_one, &pivot_two,
					stack_a);
		}
		else
			ra(stack_a);
	}
}
